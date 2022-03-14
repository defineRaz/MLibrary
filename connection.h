
#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

/**
 * @brief Connection,
 *Creates the connection between Database and the project
 *@param path - The folder where the EXE is being at
 */
static bool createConnection(QString path)
{
    path.append("/word.sqlite");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  //  db.setDatabaseName("word.sqlite");
    db.setDatabaseName(path);
    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }


    /*
    QSqlQuery query;
    query.exec("create table person (id int primary key, "
               "firstname varchar(20), lastname varchar(20))");
    query.exec("insert into person values(1, 'Danny', 'Young')");
    query.exec("insert into person values(2, 'Christine', 'Holand')");
    query.exec("insert into person values(3, 'Lars', 'Gordon')");
    query.exec("insert into person values(4, 'Roberto', 'Robitaille')");
    query.exec("insert into person values(5, 'Maria', 'Papadopoulos')");*/

    QSqlQuery query;
    query.exec("create table word (id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "english varchar(20),hungary varchar(20))");



    return true;
}


#endif
