#include "logindlg.h"
#include "ui_logindlg.h"
#include <QMessageBox>

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::on_loginButton_clicked()
{
    QString account = ui->accountText->text();
    QString password = ui->passwordText->text();
    if(account=="123"&&password=="123"){
        accept();
    }else{
        QMessageBox::warning(this, "Waring","user name or password error!",QMessageBox::Yes);
    }
}
