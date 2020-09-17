/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QPushButton *loginButton;
    QLineEdit *accountText;
    QLineEdit *passwordText;
    QLabel *label;
    QLabel *label_2;
    QPushButton *exitButton;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QString::fromUtf8("LoginDlg"));
        LoginDlg->resize(597, 447);
        loginButton = new QPushButton(LoginDlg);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(170, 350, 91, 31));
        accountText = new QLineEdit(LoginDlg);
        accountText->setObjectName(QString::fromUtf8("accountText"));
        accountText->setGeometry(QRect(250, 220, 161, 41));
        passwordText = new QLineEdit(LoginDlg);
        passwordText->setObjectName(QString::fromUtf8("passwordText"));
        passwordText->setGeometry(QRect(250, 280, 161, 41));
        label = new QLabel(LoginDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 230, 81, 31));
        label_2 = new QLabel(LoginDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 281, 101, 31));
        exitButton = new QPushButton(LoginDlg);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(330, 350, 81, 31));

        retranslateUi(LoginDlg);
        QObject::connect(exitButton, SIGNAL(clicked()), LoginDlg, SLOT(exec()));
        QObject::connect(loginButton, SIGNAL(clicked()), LoginDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QCoreApplication::translate("LoginDlg", "LoginDlg", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginDlg", "Login", nullptr));
        label->setText(QCoreApplication::translate("LoginDlg", "Account", nullptr));
        label_2->setText(QCoreApplication::translate("LoginDlg", "Password", nullptr));
        exitButton->setText(QCoreApplication::translate("LoginDlg", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
