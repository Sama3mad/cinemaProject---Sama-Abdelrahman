#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "ui_login.h" // Include the generated ui_login.h file

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots: // Make sure to use private slots for Qt signals/slots
    void on_pushButtonlogin_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
