#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QLineEdit"
#include "QPushButton"
#include "QIntValidator"
#include "QDebug"
#include "QMessageBox"

class QLineEdit *namel,*pass;
class QPushButton *bot;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    namel=ui->lineEdit_namel;
    pass=ui->lineEdit_pass;

    bot=ui->pushButton;
    bot->setEnabled(false);

    ///////// dec
    connect(pass,SIGNAL(textChanged(QString)),this,SLOT(hidbot()));


}

void MainWindow::hidbot(){

 qDebug()<<"12";
    switch (pass->text().length()) {
    case 0:
       bot->setEnabled(false);
        break;
    case 1:
          bot->setEnabled(true);
        break;
    default:
        break;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox *msg=new QMessageBox();
    msg->setInformativeText("اطلاعات ذخیره شد!");
    msg->setIcon(QMessageBox::Information);
    msg->exec();
}
