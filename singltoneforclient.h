#ifndef SINGLTONEFORCLIENT_H
#define SINGLTONEFORCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class Singltoneforclient;

class SingltoneforclientDestroyer
{
private:
    Singltoneforclient* p_instance;

public:

    ~SingltoneforclientDestroyer() { delete p_instance; }

    void initialize(Singltoneforclient* p) { p_instance = p; }

};

class Singltoneforclient : public QObject
{
    Q_OBJECT

private:
    static Singltoneforclient* p_instance;
    static SingltoneforclientDestroyer destroyer;
    QTcpSocket* mTcpSocket;

private slots:

    void slotServerRead();

protected:

    explicit Singltoneforclient(QObject* parent = nullptr);

    Singltoneforclient(Singltoneforclient&) = delete;

    Singltoneforclient& operator=(Singltoneforclient&) = delete;

    friend class ClientDestroyer;

public:

    static Singltoneforclient* getInstance();

    void sendMsgToServer(QString msg);

signals:

    void msgFromServer(QString msg);
};

#endif
