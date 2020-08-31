#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include<QString>
#include<QTextEdit>
#include <QLineEdit>
#include"op.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QDesktopWidget * desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2,(desktop->height() - this->height())/2);//窗口参数居中
    ui->setupUi(this);//创建窗口
    ui->lineEdit->setText("0");//设置初始文本为0


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Bmul_clicked()//乘号
{
    s+="*";
    ui->lineEdit->setText(s);
}

void MainWindow::on_Beq_clicked()//等于
{
    r=this->op(s.toStdString());
    s=QString::number(r);
    ui->lineEdit->setText(s);
}

void MainWindow::on_B1_clicked()
{
    s+="1";
    ui->lineEdit->setText(s);
}

void MainWindow::on_B2_clicked()
{
    s+="2";
    ui->lineEdit->setText(s);
}

void MainWindow::on_B3_clicked()
{
    s+="3";
    ui->lineEdit->setText(s);
}

void MainWindow::on_B4_clicked()
{
    s+="4";
    ui->lineEdit->setText(s);
}

void MainWindow::on_B5_clicked()
{
    s+="5";
    ui->lineEdit->setText(s);
}

void MainWindow::on_B6_clicked()
{
    s+="6";
    ui->lineEdit->setText(s);
}

void MainWindow::on_B7_clicked()
{
    s+="7";
    ui->lineEdit->setText(s);
}

void MainWindow::on_B8_clicked()
{
    s+="8";
    ui->lineEdit->setText(s);
}

void MainWindow::on_B9_clicked()
{
    s+="9";
    ui->lineEdit->setText(s);
}

void MainWindow::on_B0_clicked()
{
    s+="0";
    ui->lineEdit->setText(s);
}

void MainWindow::on_Bdot_clicked()
{
    //if(s.end()!=".")
    //{
        s+=".";
        ui->lineEdit->setText(s);
    //}
}

void MainWindow::on_Bdiv_clicked()
{
    s+="/";
    ui->lineEdit->setText(s);
}

void MainWindow::on_Bsub_clicked()
{
    s+="-";
    ui->lineEdit->setText(s);
}

void MainWindow::on_Badd_clicked()
{
    s+="+";
    ui->lineEdit->setText(s);
}

void MainWindow::on_Bce_clicked()
{
    s.clear();
    ui->lineEdit->setText(s);
}
