#include "login.h"
#include "ui_login.h"
#include "Users.h"
#include "welcome.h"
#include "register.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->labelError->setVisible(0);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    for(int i=0;i<100;i++){
        if(username==usernames[i] && password ==passwords[i]){
            hide();
            Welcome* welcomeWindow = new Welcome(this);
            welcomeWindow->show();
            welcomeWindow->setnameandage(username,ages[i]);

        }
        ui->labelError->setVisible(1);
    }

}


void Login::on_pushButton_2_clicked()
{
    hide();
    Register* registerWindow = new Register(this);
    registerWindow->show();

}

