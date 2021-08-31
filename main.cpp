#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();//显示窗口
    return a.exec();//递归
    //以上为QT的常用main写法
}
