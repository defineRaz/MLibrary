#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
//#include "tableeditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   /* Here we need the folder path where will the exe be deployed
      at, this is obligatory*/
    QString path_loc = QApplication::applicationDirPath();

    //Create the connection between database and project
    if (!createConnection(path_loc))
                return 1;

    MainWindow w;
    //initialize the TableView with their contents, and datas
    w.setUpGUI();

    w.show();
    return a.exec();
}
