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
double MainWindow::op(string a)//&& ||处增加了括号...
{
    my_Stack<double > num;
    my_Stack<char> opera;
    my_Stack<my_struct> p;

    for ( int  i = 0; i < a.size(); i++) {
        if (a[i] == '-') {
            if (i == 0) {
                i++;
                char tem_num1[250];
                int j = 0;
                double tem_num = 0;
                while ((a[i] >= '0' && a[i] <= '9') || a[i] == '.') {
                    tem_num1[j] = a[i];
                    j++;
                    i++;
                }
                tem_num1[j] = '\0';
                tem_num = atof(tem_num1);
                my_struct uu;
                uu.ch = '\0';
                uu.type = 0;
                uu.num = -tem_num;
                p.push(uu);
                i--;

            }
            else if (a[i - 1] < '0' || a[i - 1] > '9') {
                i++;
                char tem_num1[250];
                int j = 0;
                double tem_num = 0;
                while ((a[i] >= '0' && a[i] <= '9' )|| a[i] == '.') {
                    tem_num1[j] = a[i];
                    j++;
                    i++;
                }
                tem_num1[j] = '\0';
                tem_num = atof(tem_num1);
                my_struct uu;
                uu.ch = '\0';
                uu.type = 0;
                uu.num = -tem_num;
                p.push(uu);
                i--;
            }
            else {
                my_struct uu;
                uu.type = 1;
                uu.num = 0;
                char topch;
                topch = opera.getTop();
                if (topch == '*' || topch == '/') {
                    opera.pop();
                    uu.ch = topch;
                    p.push(uu);
                    i--;
                }
                else {
                    opera.push(a[i]);

                }

            }

        }

        else if (a[i] == '+'  || a[i] == '*' || a[i] == '(' || a[i] == ')' || a[i] == '/') {
            my_struct uu;
            uu.type = 1;
            uu.num = 0;
            char topch;
            switch (a[i]) {
                case '(':
                    opera.push(a[i]);
                    break;
                case '+':
                    if (opera.empty()) {
                        opera.push(a[i]);
                    }
                    else {
                        topch = opera.getTop();
                        if (topch == '*' || topch == '/') {
                            opera.pop();
                            uu.ch = topch;
                            p.push(uu);
                            i--;
                        }
                        else {
                            opera.push(a[i]);

                        }

                    }

                    break;

                case '*':
                    opera.push(a[i]);
                    break;
                case '/':
                    opera.push(a[i]);
                    break;
                case ')':
                    {
                        while (opera.getTop() != '(') {
                            my_struct o;
                            o.type = 1;
                            o.num = 0;
                            o.ch = opera.getTop();
                            opera.pop();
                            p.push(o);
                        }
                        opera.pop();
                    }

                    break;
            }


        }
        else {
            char tem_num1[250];
            int j = 0;
            double tem_num = 0;
            while ((a[i] >= '0' && a[i] <= '9' )|| a[i] == '.') {
                tem_num1[j] = a[i];
                j++;
                i++;
            }
            tem_num1[j] = '\0';
            tem_num = atof(tem_num1);
            my_struct uu;
            uu.ch = '\0';
            uu.type = 0;
            uu.num = tem_num;
            p.push(uu);
            i--;
        }


    }
    while (opera.empty() != 1) {
        my_struct uu;
        uu.type = 1;
        uu.num = 0;
        uu.ch = opera.pop();
        p.push(uu);
    }
    my_struct uu;
    uu.type = 1;
    uu.num = 0;
    uu.ch = '\0';
    p.push(uu);
    my_Stack<my_struct> pt;

    while (p.empty() == 0) {
        pt.push(p.pop());
    }

    while (pt.empty() == 0) {
        my_struct u;
        u = pt.pop();
        if ( u.ch =='\0'&&u.type==1)
            break;
        if (u.type == 0) {
            num.push(u.num);
        }
        else {
            double c;
            double t;
            switch (u.ch) {
            case '+':
                 c = num.pop();
                t = num.pop();
                num.push(c + t);
                break;
            case '-':
                 c = num.pop();
                 t = num.pop();
                num.push(t - c);
                break;
            case '*':
                 c = num.pop();
                 t = num.pop();
                num.push(c*t);
                break;
            case '/':
                 c = num.pop();
                 t = num.pop();
                num.push(t/c);
                break;
            }
        }

    }
    //cout << num.pop() << endl;

    return num.pop();
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
