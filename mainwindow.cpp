#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include<QString>
#include<QTextEdit>
#include <QLineEdit>
#include <QDebug>
#include"op.h"

QFont font_big ("KaiTi",30,52);//楷体，30号字，权重52（加粗一点点）
QFont font_normal ("KaiTi",14,50);//楷体，14号字，权重50（正常）
QFont font_little ("KaiTi",10,25);//楷体，10号字，权重25（字体变细）

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QDesktopWidget * desktop = QApplication::desktop();


    move((desktop->width() - this->width())/2,(desktop->height() - this->height())/2);//窗口参数居中
    ui->setupUi(this);//创建窗口

    ui->expout->setText("0");//设置初始文本为0
    ui->resout->setText("");//设置初始文本为空

}

MainWindow::~MainWindow()
{    delete ui;}

double MainWindow::op(std::string a)//计算器算法，输入计算字符串，输出double类的计算结果
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
             else if ((a[i - 1] < '0' || a[i - 1] > '9') && a[i - 1] != ')') {

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
             else {
                 my_struct uu;
                 uu.type = 1;
                 uu.num = 0;
                 char topch;
                 topch = opera.getTop();
                 if (topch == '*' || topch == '/' || topch == '-'||topch=='+') {
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

         else if (a[i] == '+' || a[i] == '*' || a[i] == '(' || a[i] == ')' || a[i] == '/') {
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
                     if (topch == '*' || topch == '/' || topch == '+'||topch=='-') {
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


                 if (opera.empty()) {
                     opera.push(a[i]);
                 }
                 else {
                     topch = opera.getTop();
                     if (topch == '*'||topch=='/') {
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
             case '/':
                 if (opera.empty()) {
                     opera.push(a[i]);
                 }
                 else {
                     topch = opera.getTop();
                     if (topch == '/'||topch=='*') {
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

bool MainWindow::exp_legal()//判断是否以 +-*/.( 结尾， 不是则返回ture
{
    if((s_exp.isEmpty()))//为空时直接返回ture，防止数组溢出
    {
        return 1;
    }
    else
    {
        if((s_exp[s_exp.length()-1]!='(')&&(s_exp[s_exp.length()-1]!='+')&&(s_exp[s_exp.length()-1]!='-')&&\
                (s_exp[s_exp.length()-1]!='*')&&(s_exp[s_exp.length()-1]!='/')&&(s_exp[s_exp.length()-1]!='.'))
            return 1;
        else
            return 0;
    }
}

void MainWindow::setfont_normal()//恢复字体到默认，在每个按键（除等号）调用
{
    ui->resout->setFont(font_little);
    ui->expout->setFont(font_normal);
}
//加乘除的结构一致，只写一个的注释，都有变更符号的功能
void MainWindow::on_Bmul_clicked()//乘号，有注释
{
    setfont_normal();
    if(s_exp.isEmpty())//表达式为空时，自动使用上次的结果
    {
        s_exp=s_out;
        s_see=s_out;
        s_exp+='*';
        s_see+="×";
        ui->expout->setText(s_see);
    }
    else if(exp_legal()&&!(s_exp.isEmpty()))//符合exp_legal函数时，追加乘号
    {
        s_exp+='*';
        s_see+="×";
        ui->expout->setText(s_see);
    }
    else if((!(exp_legal()))&&(s_exp[s_exp.length()-1]!='('))//上一个字符为符号且不是左括号时，将替换，即变更符号
    {
        s_exp[s_exp.length()-1]='*';
        s_see= s_see.left(s_see.size() - 1);
        s_see+="×";
        ui->expout->setText(s_see);
    }
}

void MainWindow::on_Bdiv_clicked()//除号
{
    setfont_normal();
    if(s_exp.isEmpty())
    {
        s_exp=s_out;
        s_see=s_out;
        s_exp+='/';
        s_see+="÷";
        ui->expout->setText(s_see);
    }
    else if(exp_legal()&&!(s_exp.isEmpty()))
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

void MainWindow::on_Badd_clicked()//加号
{
    setfont_normal();
    if(s_exp.isEmpty())
    {
        s_exp=s_out;
        s_see=s_out;
        s_exp+='+';
        s_see+="+";
        ui->expout->setText(s_see);
    }
    else if(exp_legal()&&!(s_exp.isEmpty()))
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

void MainWindow::on_Bsub_clicked()//减号，有注释
{
    setfont_normal();
    if(s_exp.isEmpty())//同上
    {
        s_exp=s_out;
        s_see=s_out;
        s_exp+='-';
        s_see+="-";
        ui->expout->setText(s_see);
    }
    else if((s_exp[s_exp.length()-1]!='+')&&(s_exp[s_exp.length()-1]!='-')&&\
            (s_exp[s_exp.length()-1]!='*')&&(s_exp[s_exp.length()-1]!='/')&&(s_exp[s_exp.length()-1]!='.'))
        //除去对左括号的限制，用以输入负数
    {
        s_exp+='-';
        s_see+="-";
        ui->expout->setText(s_see);
    }
    else if((!(exp_legal()))&&(s_exp[s_exp.length()-1]!='('))//实现变更符号
    {
        s_exp[s_exp.length()-1]='-';
        s_see= s_see.left(s_see.size() - 1);
        s_see+="-";
        ui->expout->setText(s_see);
    }
}

void MainWindow::on_Beq_clicked()//等于
{
    ui->lineEdit->setText(s_exp);//测试用，输出op的参数
    if(exp_legal())
    {
        //参数传入，将double类的传出转为qstring存入s_out
        r=this->op(s_exp.toStdString());
        s_out=QString::number(r);
        //参数清零
        s_exp.clear();
        s_see.clear();
        cur_senacc=0;

        //结果突出显示
        ui->resout->setFont(font_big);
        ui->expout->setFont(font_little);
        ui->resout->setText(s_out);
    }

}
//数字键结构一致，字符串后追加对应数字
void MainWindow::on_B1_clicked()
{
    setfont_normal();
    s_exp+="1";
    s_see+="1";
    ui->expout->setText(s_see);
}

void MainWindow::on_B2_clicked()
{
    setfont_normal();
    s_exp+="2";
    s_see+="2";
    ui->expout->setText(s_see);
}

void MainWindow::on_B3_clicked()
{
    setfont_normal();
    s_exp+="3";
    s_see+="3";
    ui->expout->setText(s_see);
}

void MainWindow::on_B4_clicked()
{
    setfont_normal();
    s_exp+="4";
    s_see+="4";
    ui->expout->setText(s_see);
}

void MainWindow::on_B5_clicked()
{
    setfont_normal();
    s_exp+="5";
    s_see+="5";
    ui->expout->setText(s_see);
}

void MainWindow::on_B6_clicked()
{
    setfont_normal();
    s_exp+="6";
    s_see+="6";
    ui->expout->setText(s_see);
}

void MainWindow::on_B7_clicked()
{
    setfont_normal();
    s_exp+="7";
    s_see+="7";
    ui->expout->setText(s_see);
}

void MainWindow::on_B8_clicked()
{
    setfont_normal();
    s_exp+="8";
    s_see+="8";
    ui->expout->setText(s_see);
}

void MainWindow::on_B9_clicked()
{
    setfont_normal();
    s_exp+="9";
    s_see+="9";
    ui->expout->setText(s_see);
}

void MainWindow::on_B0_clicked()
{
    setfont_normal();
    s_exp+="0";
    s_see+="0";
    ui->expout->setText(s_see);
}

void MainWindow::on_Bdot_clicked()//小数点键
{
    setfont_normal();
    s_exp+=".";
    s_see+=".";
    ui->expout->setText(s_see);
}

void MainWindow::on_Bac_clicked()//清空键，将会清空全部参数
{
    setfont_normal();
    s_exp.clear();
    s_see.clear();
    s_out.clear();
    cur_senacc=0;

    ui->expout->setText("0");
    ui->resout->setText("0");
}

void MainWindow::on_Bcur_left_clicked()//左括号键
{
    setfont_normal();
    if(s_exp.isEmpty())//表达式为空时，直接增加左括号
    {
        s_exp+="(";
        s_see+="(";
        cur_senacc+=1;
        ui->expout->setText(s_see);
    }
    else if((!exp_legal())&&(s_exp[s_exp.length()-1]!='.'))//上一个为符号且非小数点时追加左括号
    {
        s_exp+="(";
        s_see+="(";
        cur_senacc+=1;
        ui->expout->setText(s_see);
    }
}

void MainWindow::on_Bcur_right_clicked()//右括号
{
    setfont_normal();
    if((exp_legal())&&(cur_senacc>0))//追加右括号，限制右括号数量不会超过左括号
        {
            s_exp+=")";
            s_see+=")";
            cur_senacc-=1;
            ui->expout->setText(s_see);
        }
}

void MainWindow::on_Bback_clicked()//退格键
{
    setfont_normal();
    if(!s_exp.isEmpty())//不为空时，删除末尾的一个字符
    {
        s_exp= s_exp.left(s_exp.size() - 1);
        s_see= s_see.left(s_see.size() - 1);
        ui->expout->setText(s_see);
    }
}
