#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSql>
#include "databasemanager.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setUpGUI(){

model = new QSqlTableModel(this);
    model->setTable("word");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("ENG"));
    model->setHeaderData(2, Qt::Horizontal, tr("HUN"));


    ui->view->setModel(model);
    ui->view->resizeColumnsToContents();
    ui->view->setColumnHidden(0,true);

}

void MainWindow::on_submitButton_clicked()
{
    model->database().transaction();
        if (model->submitAll()) {
            model->database().commit();
        } else {
            model->database().rollback();
            QMessageBox::warning(this, tr("Word table"),
                                 tr("The database reported an error: %1")
                                 .arg(model->lastError().text()));
        }
}

int MainWindow::getSelectedRow(){

    int index = 0;
        index = ui->view->selectionModel()->currentIndex().row();
        return index;
}

void MainWindow::on_addButton_clicked()
{

     db->addToDB(ui->eng_Input->text(),ui->hun_Input->text());
      on_submitButton_clicked();

}


void MainWindow::on_deleteButton_clicked()
{
    int person_id = model->index(getSelectedRow(),0).data().toInt();
       db->removeFromDB(person_id);
       on_submitButton_clicked();
}


void MainWindow::on_quitButton_clicked()
{
    MainWindow::close();
}

