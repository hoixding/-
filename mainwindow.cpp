#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include<QString>
#include<QTextEdit>
#include <QLineEdit>
#include"op.h"

int cur_sentry=-1;//括号哨兵，-1、1为有效值
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
double MainWindow::op(std::string a)
{
       my_Stack<double > num;
       my_Stack<char> opera;
       my_Stack<my_struct> p;

       for (unsigned int  i = 0; i < a.size(); i++) {
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
               else if ((a[i - 1] < '0' || a[i - 1] > '9')&&a[i-1]!=')') {
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
       return num.pop();
}

bool MainWindow::exp_legal()//判断是否以+-*/.（结尾， 不是返回ture
{
    if((s_exp[s_exp.length()-1]!='(')&&(s_exp[s_exp.length()-1]!='+')&&(s_exp[s_exp.length()-1]!='-')&&\
            (s_exp[s_exp.length()-1]!='*')&&(s_exp[s_exp.length()-1]!='/')&&(s_exp[s_exp.length()-1]!='.'))
        return 1;
    else
        return 0;
}

void MainWindow::on_Bmul_clicked()//乘号
{
    if(exp_legal())
    {
        s_exp+='*';
        s_see+="×";
        ui->expout->setText(s_see);
    }
    else if((!(exp_legal()))&&(s_exp[s_exp.length()-1]!='('))
    {
        s_exp[s_exp.length()-1]='*';
        s_see= s_see.left(s_see.size() - 1);
        s_see+="×";
        ui->expout->setText(s_see);
    }
}

void MainWindow::on_Bdiv_clicked()//除号
{
    if(exp_legal())
    {
        s_exp+='/';
        s_see+="÷";
        ui->expout->setText(s_see);
    }
    else if((!(exp_legal()))&&(s_exp[s_exp.length()-1]!='('))
    {
        s_exp[s_exp.length()-1]='/';
        s_see= s_see.left(s_see.size() - 1);
        s_see+="÷";
        ui->expout->setText(s_see);
    }
}

void MainWindow::on_Badd_clicked()//加法
{
    if(exp_legal())
    {
        s_exp+='+';
        s_see+="+";
        ui->expout->setText(s_see);
    }
    else if((!(exp_legal()))&&(s_exp[s_exp.length()-1]!='('))
    {
        s_exp[s_exp.length()-1]='+';
        s_see= s_see.left(s_see.size() - 1);
        s_see+="+";
        ui->expout->setText(s_see);
    }
}

void MainWindow::on_Bsub_clicked()//减法
{
    if(exp_legal())
    {
        s_exp+='-';
        s_see+="-";
        ui->expout->setText(s_see);
    }
    else if((!(exp_legal()))&&(s_exp[s_exp.length()-1]!='('))
    {
        s_exp[s_exp.length()-1]='-';
        s_see= s_see.left(s_see.size() - 1);
        s_see+="-";
        ui->expout->setText(s_see);
    }
}

void MainWindow::on_Beq_clicked()//等于
{
    if(exp_legal())
    {
        //s_see+="=";
        r=this->op(s_exp.toStdString());
        s_out=QString::number(r);

        ui->resout->setText(s_out);
        //ui->expout->setText(s_see);
        s_exp=s_out;
        s_see=s_out;
    }
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

void MainWindow::on_Bac_clicked()
{
    s_exp.clear();
    s_see.clear();
    s_out.clear();
    ui->expout->setText("0");
    ui->resout->setText("0");
}

void MainWindow::on_Bcur_clicked()
{
    if(cur_sentry==-1)
    {
        s_exp+="(";
        s_see+="(";
        cur_sentry=1;
    }
    else if ((cur_sentry==1)&&(exp_legal()))
    {

        s_exp+=")";
        s_see+=")";
        cur_sentry=-1;
    }
    ui->expout->setText(s_see);
}

