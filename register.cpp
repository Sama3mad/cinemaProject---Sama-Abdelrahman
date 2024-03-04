#include "register.h"
#include "ui_register.h"
#include "Users.h"
#include "welcome.h"
Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->label_exist->setVisible(0);
    ui->label_notmatch->setVisible(0);
    ui->label_fields->setVisible(0);
    ui->label_age->setVisible(0);
}

Register::~Register()
{
    delete ui;
}
void Register::on_pushButton_clicked()
{
    ui->label_exist->setVisible(false);
    ui->label_notmatch->setVisible(false);
    ui->label_fields->setVisible(false);
    ui->label_age->setVisible(false);

    QString newUsername = ui->lineEditUsername->text();
    QString newPassword = ui->lineEditPassword->text();
    QString retypedPassword = ui->lineEditRetypePassword->text();
    QString age = ui->comboBox_3->currentText();

    bool check = true;

    if (!(ui->radioButtonFemale->isChecked() || ui->radioButtonMale->isChecked()) ||
        !(ui->radioButtonUser->isChecked() || ui->radioButtonAdmin->isChecked()) ||
        !(ui->checkBox->isChecked() || ui->checkBox_2->isChecked() || ui->checkBox_3->isChecked() || ui->checkBox_4->isChecked() || ui->checkBox_5->isChecked() || ui->checkBox_6->isChecked()))
    {
        ui->label_fields->setVisible(true);
        check = false;
    }

    for (int i = 0; i < 100; i++) { // Replace numberOfUsernames with the actual size of usernames array
        if (newUsername == usernames[i]) {
            ui->label_exist->setVisible(true);
            check = false;
        }
    }

    if (newPassword != retypedPassword) {
        ui->label_notmatch->setVisible(true);
        check = false;
    }

    if (age == "after 2012 (below 12)") { // Consider using a numeric comparison or a range check for age
        ui->label_age->setVisible(true);
        check = false;
    }

    if (check) {
        usernames[usersCount]=newUsername;
        passwords[usersCount]=newPassword;
        ages[usersCount]= 2024-age.toInt();
        hide();
        Welcome* welcomeWindow = new Welcome(this);
        welcomeWindow->show();
        welcomeWindow->setnameandage(newUsername,ages[usersCount]);
    }
}
