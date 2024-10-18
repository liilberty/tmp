#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H

#include <QString>
#include <QStringList>
#include <QByteArray>


QByteArray parsing(QString data_from_client);


QByteArray auth(QString log, QString pass);


QByteArray reg(QString log, QString pass, QString mail);


QByteArray task1();


QByteArray task2();


QByteArray task3();


QByteArray task4();


QByteArray check(QString log, QString pass, QString mail);

#endif
