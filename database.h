#ifndef DATABASE_H
#define DATABASE_H

#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QStringList>

class DataBase;

class DatabaseDestroyer
{
private:
    DataBase * p_instance;
public:
    ~DatabaseDestroyer();

    void initialize(DataBase * p);
};

class DataBase {
private:
    static DataBase *p_instance;
    static DatabaseDestroyer destroyer;
    QSqlDatabase db;


    DataBase();

    ~DataBase();


    DataBase(const DataBase&) = delete;

    void operator= (const DataBase&) = delete;


    friend class DatabaseDestroyer;

public:

    bool createTable();

    static DataBase& getInstance();


    QSqlDatabase& getDatabase();


    QStringList queryToDatabase(QStringList query);
};

#endif
