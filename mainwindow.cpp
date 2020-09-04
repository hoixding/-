#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include<QString>
#include<QTextEdit>
#include <QLineEdit>
#include <QDebug>
#include"op.h"
#include "calculator.h"
QFont font_big ("KaiTi",30,52);//楷体，30号字，权重52（加粗一点点）
QFont font_normal ("KaiTi",20,50);//楷体，14号字，权重50（正常）
QFont font_little ("KaiTi",12,25);//楷体，10号字，权重25（字体变细）

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QDesktopWidget * desktop = QApplication::desktop();


    move((desktop->width() - this->width())/2,(desktop->height() - this->height())/2);//窗口参数居中
    ui->setupUi(this);//创建窗口

    ui->expout->setText("0");//设置初始文本为0
    ui->resout->setText("");//设置初始文本为空
    ui->B0->setStyleSheet("QPushButton:hover{background-color: rgb(219,219,219);} "
                            "QPushButton{color:rgb(0, 0, 0);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";}"
                            "QPushButton:pressed{background-color:rgb(200,200,200);} ");
      ui->B1->setStyleSheet("QPushButton:hover{background-color: rgb(219,219,219);} "
                            "QPushButton{color:rgb(0, 0, 0);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";}"
                            "QPushButton:pressed{background-color:rgb(200,200,200);} ");
      ui->B2->setStyleSheet("QPushButton:hover{background-color: rgb(219,219,219);} "
                            "QPushButton{color:rgb(0, 0, 0);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";}"
                            "QPushButton:pressed{background-color:rgb(200,200,200);} ");
      ui->B3->setStyleSheet("QPushButton:hover{background-color: rgb(219,219,219);} "
                            "QPushButton{color:rgb(0, 0, 0);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";}"
                            "QPushButton:pressed{background-color:rgb(200,200,200);} ");
      ui->B4->setStyleSheet("QPushButton:hover{background-color: rgb(219,219,219);} "
                            "QPushButton{color:rgb(0, 0, 0);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";}"
                            "QPushButton:pressed{background-color:rgb(200,200,200);} ");
      ui->B5->setStyleSheet("QPushButton:hover{background-color: rgb(219,219,219);} "
                            "QPushButton{color:rgb(0, 0, 0);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";}"
                            "QPushButton:pressed{background-color:rgb(200,200,200);} ");
      ui->B6->setStyleSheet("QPushButton:hover{background-color: rgb(219,219,219);} "
                            "QPushButton{color:rgb(0, 0, 0);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";}"
                            "QPushButton:pressed{background-color:rgb(200,200,200);} ");
      ui->B7->setStyleSheet("QPushButton:hover{background-color: rgb(219,219,219);} "
                            "QPushButton{color:rgb(0, 0, 0);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";}"
                            "QPushButton:pressed{background-color:rgb(200,200,200);} ");
      ui->B8->setStyleSheet("QPushButton:hover{background-color: rgb(219,219,219);} "
                            "QPushButton{color:rgb(0, 0, 0);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";}"
                            "QPushButton:pressed{background-color:rgb(200,200,200);} ");
      ui->B9->setStyleSheet("QPushButton:hover{background-color: rgb(219,219,219);} "
                            "QPushButton{color:rgb(0, 0, 0);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";}"
                            "QPushButton:pressed{background-color:rgb(200,200,200);} ");
      ui->Beq->setStyleSheet("QPushButton:hover{background-color: rgb(224,224,225);} "
                            "QPushButton{color:rgb(255, 148, 82);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";background-color:rgb(246,246,246);}"
                            "QPushButton:pressed{background-color:rgb(205,205,205);} ");
      ui->Badd->setStyleSheet("QPushButton:hover{background-color: rgb(224,224,225);} "
                            "QPushButton{color:rgb(255, 148, 82);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";background-color:rgb(246,246,246);}"
                            "QPushButton:pressed{background-color:rgb(205,205,205);} ");
      ui->Bsub->setStyleSheet("QPushButton:hover{background-color: rgb(224,224,225);} "
                            "QPushButton{color:rgb(255, 148, 82);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";background-color:rgb(246,246,246);}"
                            "QPushButton:pressed{background-color:rgb(205,205,205);} ");
      ui->Bmul->setStyleSheet("QPushButton:hover{background-color: rgb(224,224,225);} "
                            "QPushButton{color:rgb(255, 148, 82);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";background-color:rgb(246,246,246);}"
                            "QPushButton:pressed{background-color:rgb(205,205,205);} ");
      ui->Bdiv->setStyleSheet("QPushButton:hover{background-color: rgb(224,224,225);} "
                            "QPushButton{color:rgb(255, 148, 82);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";background-color:rgb(246,246,246);}"
                            "QPushButton:pressed{background-color:rgb(205,205,205);} ");
      ui->Bac->setStyleSheet("QPushButton:hover{background-color: rgb(224,224,225);} "
                            "QPushButton{color:rgb(255, 148, 82);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";background-color:rgb(246,246,246);}"
                            "QPushButton:pressed{background-color:rgb(205,205,205);} ");
      ui->Bback->setStyleSheet("QPushButton:hover{background-color: rgb(224,224,225);} "
                            "QPushButton{color:rgb(255, 148, 82);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";background-color:rgb(246,246,246);}"
                            "QPushButton:pressed{background-color:rgb(205,205,205);} ");
      ui->Bcur_right->setStyleSheet("QPushButton:hover{background-color: rgb(224,224,225);} "
                            "QPushButton{color:rgb(255, 148, 82);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";background-color:rgb(246,246,246);}"
                            "QPushButton:pressed{background-color:rgb(205,205,205);} ");
      ui->Bcur_left->setStyleSheet("QPushButton:hover{background-color: rgb(224,224,225);} "
                            "QPushButton{color:rgb(255, 148, 82);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";background-color:rgb(246,246,246);}"
                            "QPushButton:pressed{background-color:rgb(205,205,205);} ");
      ui->Bdot->setStyleSheet("QPushButton:hover{background-color: rgb(224,224,225);} "
                            "QPushButton{color:rgb(255, 148, 82);border:3px solid  rgb(235,235,235);font: 18pt  \"Arial\";background-color:rgb(246,246,246);}"
                            "QPushButton:pressed{background-color:rgb(205,205,205);} ");

}

MainWindow::~MainWindow()
{    delete ui;}

double MainWindow::op(std::string a)//计算器算法，输入计算字符串，输出double类的计算结果
{
       calculator b;
       b.Infix_to_suffix(a);
       return b.Suffix_expression_calculation() ;
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
        if(!(s_out.isEmpty()))
        {
        s_exp=s_out;
        s_see=s_out;
        s_exp+='*';
        s_see+="×";
        ui->expout->setText(s_see);
        }
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
        if(!(s_out.isEmpty()))
        {
        s_exp=s_out;
        s_see=s_out;
        s_exp+='/';
        s_see+="÷";
        ui->expout->setText(s_see);
        }
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
        if(!(s_out.isEmpty()))
        {
        s_exp=s_out;
        s_see=s_out;
        s_exp+='+';
        s_see+="+";
        ui->expout->setText(s_see);
        }
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
    if(s_exp.left(1)=='+')
    {
        s_exp=s_exp.right(s_exp.length()-1);
    }
    if((s_exp.left(1)=='*')||(s_exp.left(1)=='/')\
            ||(s_exp.indexOf("(*",0,Qt::CaseInsensitive)!=-1)||(s_exp.indexOf("(/",0,Qt::CaseInsensitive)!=-1||\
                                                        (s_exp.indexOf("(+",0,Qt::CaseInsensitive)!=-1)))
    {
        s_exp.clear();
        s_see.clear();
        ui->expout->setText("0");
        ui->resout->setText("0");
    }
    else if(s_exp.isEmpty())
    {
        ui->resout->setFont(font_big);
        ui->expout->setFont(font_little);
        ui->resout->setText(s_out);
    }
   else if(exp_legal()&&(cur_senacc==0))
    {
        //参数传入，将double类的传出转为qstring存入s_out
        r=this->op(s_exp.toStdString());
        s_out=QString("%1").arg(r, 0, 'f', 9);//保持有效数字，不用科学计数法
        if(s_out.indexOf('.',1,Qt::CaseInsensitive)!=-1)
        {
           while(s_out.right(1)=='0')
                s_out=s_out.left(s_out.size() - 1);
           if(s_out.right(1)=='.')
                s_out=s_out.left(s_out.size() - 1);
        }//丢弃末尾的0以及.

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
    if(exp_legal())
    {
        s_exp+=".";
        s_see+=".";
        ui->expout->setText(s_see);
    }
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
        if(s_exp.right(1)==')')//删除字符为右括号时，括号计数器+1
            cur_senacc+=1;
        s_exp= s_exp.left(s_exp.size() - 1);
        s_see= s_see.left(s_see.size() - 1);
        ui->expout->setText(s_see);
    }
}
