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

    double op(std::string a);
    bool exp_legal();
    int cur_senacc=0;//括号计数器
    QString s_exp="";//传入op的参数，默认为空
    QString s_see="";//看到的表达式
    QString s_out="";//结果
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

    void on_Bac_clicked();

    void on_Bcur_left_clicked();

    void on_Bcur_right_clicked();

private:
    Ui::MainWindow *ui;

    double r;

};

#endif // MAINWINDOW_H
