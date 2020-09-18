#include "mainwindow.h"

#include "logindlg.h"
#include "httpclient.h"

#include <QApplication>
#include <QtGui>


int main(int argc, char *argv[])
{
    HttpClient *client = new HttpClient();
    QJsonObject content;

    QApplication a(argc, argv);
    MainWindow w;
        LoginDlg dlg;
        if (dlg.exec() == QDialog::Accepted)
        {
           w.show();
           return a.exec();
        }
    else return 0;
}
