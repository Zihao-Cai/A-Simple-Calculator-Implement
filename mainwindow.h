#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void oneclicked();
    void twoclicked();
    void threeclicked();
    void fourclicked();
    void fiveclicked();
    void sixclicked();
    void sevenclicked();
    void eightclicked();
    void nineclicked();
    void zeroclicked();
    void addclicked();
    void subtractclicked();
    void multiplyclicked();
    void divideclicked();
    void negateclicked();
    void equalclicked();
    void clearclicked();
    void backclicked();
    void lpareclicked();
    void rpareclicked();
    void dotclicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
