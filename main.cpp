#include <QCoreApplication>
#include "database.h"
#include "tcpserver.h"
#include "functionsforserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DataBase& dbInstance = DataBase::getInstance();

    TcpServer myserv;
    return a.exec();
}

