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
    void dda_algo(float x1, float y1, float x2, float y2, QRgb color);
    void dda_algo_1(float x1, float y1, float x2, float y2, QRgb color);
//    void mousePressEvent(QMouseEvent *event);
    void clip(float x1, float y1, float x2, float y2);
    void getcode(int a[], float x, float y);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
