#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include<string>
#include"op.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double op(std::string a)
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

    QString s="";
private slots:
    void on_B1_clicked();

    void on_B2_clicked();

    void on_Bmul_clicked();

    void on_Beq_clicked();

    void on_B3_clicked();

    void on_B4_clicked();

    void on_B5_clicked();

    void on_B6_clicked();

    void on_B7_clicked();

    void on_B8_clicked();

    void on_B9_clicked();

    void on_B0_clicked();

    void on_Bdot_clicked();

    void on_Bdiv_clicked();

    void on_Bsub_clicked();

    void on_Badd_clicked();

    void on_Bce_clicked();

private:
    Ui::MainWindow *ui;

    double r;

};

#endif // MAINWINDOW_H
