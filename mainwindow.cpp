#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "calculate.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font("微软雅黑",22,QFont::Bold,true);
    ui->inputbox->setFont(font);
    ui->resultbox->setFont(font);
    connect(ui->one,SIGNAL(clicked()),this,SLOT(oneclicked()));
    connect(ui->two,SIGNAL(clicked()),this,SLOT(twoclicked()));
    connect(ui->three,SIGNAL(clicked()),this,SLOT(threeclicked()));
    connect(ui->four,SIGNAL(clicked()),this,SLOT(fourclicked()));
    connect(ui->five,SIGNAL(clicked()),this,SLOT(fiveclicked()));
    connect(ui->six,SIGNAL(clicked()),this,SLOT(sixclicked()));
    connect(ui->seven,SIGNAL(clicked()),this,SLOT(sevenclicked()));
    connect(ui->eight,SIGNAL(clicked()),this,SLOT(eightclicked()));
    connect(ui->nine,SIGNAL(clicked()),this,SLOT(nineclicked()));
    connect(ui->zero,SIGNAL(clicked()),this,SLOT(zeroclicked()));
    connect(ui->add,SIGNAL(clicked()),this,SLOT(addclicked()));
    connect(ui->subtract,SIGNAL(clicked()),this,SLOT(subtractclicked()));
    connect(ui->multiply,SIGNAL(clicked()),this,SLOT(multiplyclicked()));
    connect(ui->divide,SIGNAL(clicked()),this,SLOT(divideclicked()));
    connect(ui->negate,SIGNAL(clicked()),this,SLOT(negateclicked()));
    connect(ui->equal,SIGNAL(clicked()),this,SLOT(equalclicked()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(clearclicked()));
    connect(ui->back,SIGNAL(clicked()),this,SLOT(backclicked()));
    connect(ui->lpare,SIGNAL(clicked()),this,SLOT(lpareclicked()));
    connect(ui->rpare,SIGNAL(clicked()),this,SLOT(rpareclicked()));
    connect(ui->dot,SIGNAL(clicked()),this,SLOT(dotclicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString inputstr = "";
QString resultstr = "";
void MainWindow::oneclicked()
{//输入一
    ui->resultbox->setText("");
   inputstr = ui->inputbox->text().append("1");
   ui->inputbox->setText(inputstr);
   return;
}

void MainWindow::twoclicked()
{
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("2");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::threeclicked()
{
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("3");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::fourclicked()
{
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("4");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::fiveclicked()
{
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("5");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::sixclicked()
{
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("6");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::sevenclicked()
{
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("7");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::eightclicked()
{
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("8");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::nineclicked()
{
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("9");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::zeroclicked()
{//输入零
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("0");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::addclicked()
{//加号
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("+");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::subtractclicked()
{//减号
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("-");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::multiplyclicked()
{//乘号
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("*");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::divideclicked()
{//除号
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("/");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::negateclicked()
{//取反符号
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("#");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::lpareclicked()
{
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append("(");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::rpareclicked()
{
     ui->resultbox->setText("");
    inputstr = ui->inputbox->text().append(")");
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::equalclicked()
{//开始分析inputbox表达式内容,分析代码如下:
    int signal = 1;//信号量signal初始化为1并传入计算器，1代表一切正常，0代表除数为0的情况，-1代表表达式有误//
    ui->resultbox->clear();
    QString t = ui->inputbox->text();
    resultstr = calculate(t,&signal);
    ui->resultbox->setText(resultstr);
    QPixmap img(":/confused.png");
    QIcon ic = QIcon(img);
    if(signal == -1){
        QMessageBox box;
        box.setWindowIcon(ic);
        box.setStyleSheet("color:red");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("option");
        box.setText("Expression error!");
        box.exec();
    }if(signal == 0){
        QMessageBox box;
        box.setWindowIcon(ic);
        box.setStyleSheet("color:blue");
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("option");
        box.setText("The divisor cannot be 0!");
        box.exec();
    }

    return;
}

void MainWindow::backclicked()
{//回退
     ui->resultbox->setText("");
    inputstr.chop(1);
    ui->inputbox->setText(inputstr);
    return;
}

void MainWindow::clearclicked()
{//清空
     ui->resultbox->setText("");
    inputstr.clear();
    ui->inputbox->setText(inputstr);
    return;
}





void MainWindow::dotclicked()
{
    ui->resultbox->setText("");
   inputstr = ui->inputbox->text().append(".");
   ui->inputbox->setText(inputstr);
   return;
}
