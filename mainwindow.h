#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QSqlTableModel;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
     * @brief Initialize tableview,
     * Initialize tableview with their contents, and datas
     */
    void setUpGUI();

    databasemanager *db = new databasemanager();

private slots:
    /**
     * @brief Returns selected Row database ID,
     * Returns the object database ID
     */
     int getSelectedRow();

     /**
      * @brief Commits the changes,
      * Changes only be executed by this method callin
      */
     void on_submitButton_clicked();

     /**
      * @brief Add new object
      */
     void on_addButton_clicked();

     /**
      * @brief Remove selected object
      */
     void on_deleteButton_clicked();

     /**
      * @brief Close the project
      */
     void on_quitButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
};
#endif // MAINWINDOW_H
