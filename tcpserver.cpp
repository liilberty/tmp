#include "tcpserver.h"
#include "functionsforserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>

TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &TcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333)) {
        qDebug() << "Server is not started";
    } else {
        qDebug() << "Server is started";
    }
}

TcpServer::~TcpServer()
{
    mTcpServer->close();
    qDeleteAll(mTcpSockets);
    mTcpSockets.clear();
}

void TcpServer::slotNewConnection()
{
    QTcpSocket *clientSocket = mTcpServer->nextPendingConnection();
    mTcpSockets << clientSocket;

    connect(clientSocket, &QTcpSocket::readyRead, this, &TcpServer::slotServerRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &TcpServer::slotClientDisconnected);

    clientSocket->write("Hello, World!!! I am echo server!\r\n");
}

void TcpServer::slotServerRead()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket)
        return;

    QString res = "";
    while (clientSocket->bytesAvailable() > 0) {
        QByteArray array = clientSocket->readAll();
        res.append(array);
    }
    qDebug() << res;
    clientSocket->write(parsing(res));
}

void TcpServer::slotClientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket)
        return;

    mTcpSockets.removeOne(clientSocket);
    clientSocket->deleteLater();
}
