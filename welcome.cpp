#include "welcome.h"
#include "ui_welcome.h"
#include "Users.h"
#include "login.h"
Welcome::Welcome(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Welcome)
{
    ui->setupUi(this);
QPixmap pix("images/FinalStep.jpg");
    int w = ui->Image->width();
    int h = ui->Image->height();
    ui->Image->setPixmap(pix.scaled (w,h, Qt:: KeepAspectRatio));
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::setnameandage(QString username, int age){
    ui->Hello->setText("Hello "+username+ " "+ QString :: number (age));
}

void Welcome::on_pushButton_clicked()
{
    hide();
    login *loginWindow = new login (this);
    loginWindow->show();
}

