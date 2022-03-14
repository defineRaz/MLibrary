#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>


class databasemanager
{
        public:

            /**
             * @brief Constructor,
             *Constructor sets up for sql commands
             */
            databasemanager();

            /**
             * @brief Destructor,
             * Destroys the databasemanager
             */
            ~databasemanager();

            /**
             * @brief Remove object,
             * Removes the selected row object from the database
             * @param identifier - selected objec database id
             */
            bool removeFromDB(const int& identifier);

            /**
             * @brief Add object,
             * Adds a new object to the database, from user input
             * @param english - input variable from user
             * @param hungary - input variable from user
             */
            bool addToDB(const QString& english,const QString& hungary);

};

#endif // DATABASEMANAGER_H
