#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include<QString>
#include<QTextEdit>
#include <QLineEdit>
#include"op.h"

int sentry=-1;//哨兵，-1、1为有效值
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QDesktopWidget * desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2,(desktop->height() - this->height())/2);//窗口参数居中
    ui->setupUi(this);//创建窗口
    ui->expout->setText("0");//设置初始文本为0
    ui->resout->setText("0");//设置初始文本为0

}

MainWindow::~MainWindow()
{    delete ui;}
void MainWindow::on_Bmul_clicked()//乘号
{
    s_exp+="*";
    s_see+="×";
    ui->expout->setText(s_see);
}

void MainWindow::on_Beq_clicked()//等于
{
    //s_see+="=";
    r=this->op(s_exp.toStdString());
    s_out=QString::number(r);

    ui->resout->setText(s_out);
    //ui->expout->setText(s_see);
    s_exp=s_out;
    s_see=s_out;
}

void MainWindow::on_B1_clicked()
{
    s_exp+="1";
    s_see+="1";
    ui->expout->setText(s_see);
}

void MainWindow::on_B2_clicked()
{
    s_exp+="2";
    s_see+="2";
    ui->expout->setText(s_see);
}

void MainWindow::on_B3_clicked()
{
    s_exp+="3";
    s_see+="3";
    ui->expout->setText(s_see);
}

void MainWindow::on_B4_clicked()
{
    s_exp+="4";
    s_see+="4";
    ui->expout->setText(s_see);
}


void MainWindow::on_B5_clicked()
{
    s_exp+="5";
    s_see+="5";
    ui->expout->setText(s_see);
}

void MainWindow::on_B6_clicked()
{
    s_exp+="6";
    s_see+="6";
    ui->expout->setText(s_see);
}


void MainWindow::on_B7_clicked()
{
    s_exp+="7";
    s_see+="7";
    ui->expout->setText(s_see);
}

void MainWindow::on_B8_clicked()
{
    s_exp+="8";
    s_see+="8";
    ui->expout->setText(s_see);
}
void MainWindow::on_B9_clicked()
{
    s_exp+="9";
    s_see+="9";
    ui->expout->setText(s_see);
}

void MainWindow::on_B0_clicked()
{
    s_exp+="0";
    s_see+="0";
    ui->expout->setText(s_see);
}

void MainWindow::on_Bdot_clicked()
{
    s_exp+=".";
    s_see+=".";
    ui->expout->setText(s_see);
}
void MainWindow::on_Bdiv_clicked()
{
    s_exp+="/";
    s_see+="÷";
    ui->expout->setText(s_see);
}

void MainWindow::on_Bsub_clicked()
{
    s_exp+="-";
    s_see+="-";
    ui->expout->setText(s_see);
}

void MainWindow::on_Bac_clicked()
{
    s_exp.clear();
    s_see.clear();
    s_out.clear();
    ui->expout->setText("0");
    ui->resout->setText("0");
}

void MainWindow::on_Badd_clicked()
{
    s_see+="+";
    s_exp+="+";
    ui->expout->setText(s_see);
}

void MainWindow::on_Bcur_clicked()
{
    if(sentry==-1)
    {
        s_exp+="(";
        s_see+="(";
        sentry=1;
    }
    else if ((sentry==1)&&(exp_legal())) {

        s_exp+=")";
        s_see+=")";
        sentry=-1;
    }
    ui->expout->setText(s_see);
}
