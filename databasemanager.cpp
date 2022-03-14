#include "databasemanager.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>



databasemanager::databasemanager(){};
databasemanager::~databasemanager(){};

bool databasemanager::removeFromDB(const int& identifier) {
    bool success = false;

   QSqlQuery query;
   query.prepare("DELETE FROM word WHERE id = (:id)");
   query.bindValue(":id", identifier);
   success = query.exec();
   if(!success){
       qDebug() << "removeWord error:"
                << query.lastError();

       QMessageBox::critical(nullptr, QObject::tr("Error during remove"),
           QObject::tr("Unable to remove the selected object from the database.\n"
                       "Click Cancel to exit."), QMessageBox::Cancel);

        }

    return success;
};

bool databasemanager::addToDB(const QString& english,const QString& hungary) {
    bool success = false;

       QSqlQuery query;
       query.prepare("INSERT INTO word (english,hungary) VALUES (:english, :hungary)");
       query.bindValue(":english", english);
       query.bindValue(":hungary", hungary);

       if(query.exec())
       {success = true;}
       else {
       qDebug() << "addperson error:" << query.lastError();

       QMessageBox::critical(nullptr, QObject::tr("Error during add"),
           QObject::tr("Unable to add the created object to the database.\n"
                       "Click Cancel to exit."), QMessageBox::Cancel);

       }

       return success;
}
