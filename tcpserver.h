#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>


class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

    ~TcpServer();

private slots:

    void slotNewConnection();

    void slotServerRead();

    void slotClientDisconnected();

private:
    QTcpServer *mTcpServer;
    QList<QTcpSocket*> mTcpSockets;
};

#endif
