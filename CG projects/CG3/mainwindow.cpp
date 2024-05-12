#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QApplication>
#include <QMouseEvent>
#include <QColorDialog>
#include <QColor>
#include <iostream>
using namespace std;
// required for mouse press
int X[15], Y[15];
bool start = true;
int ver = -1;

QColor col1;
QRgb color;
QImage image(400, 400, QImage::Format_RGB888);
QImage image_1(400, 400, QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    col1 = QColorDialog::getColor();
    color = col1.rgb();
}

//void MainWindow :: mousePressEvent(QMouseEvent *event)
//{
//    int x, y;
//    x = event->pos().x();
//    y = event->pos().y();
//    if(start)
//    {
//        if(event->button() == Qt::RightButton)
//        {
//            dda_algo(X[ver], Y[ver], X[0], Y[0], color);
//            start = false;
//        }
//        else if(ver == -1)
//        {
//            ver++;
//            X[ver] = x;
//            Y[ver] = y;
//        }
//        else
//        {
//            ver++;
//            X[ver] = x;
//            Y[ver] = y;
//            dda_algo(X[ver], Y[ver], X[ver-1], Y[ver - 1],color);
//        }
//        ui->label->setPixmap(QPixmap::fromImage(image));
//    }
//}

void MainWindow:: dda_algo(float x1, float y1, float x2, float y2, QRgb color)
{
    float dx, dy, x, y, x_inc, y_inc;
    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    int i;
    int length;
    if (abs(dx) >= abs(dy))
        length = abs(dx);
    else
        length = abs(dy);
    image.setPixel(x, y, color);
    x_inc = dx / length;
    y_inc = dy / length;
    for(i = 0; i < length; i++)
    {
        x = x + x_inc;
        y = y + y_inc;
        image.setPixel(x, y, color);
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow:: dda_algo_1(float x1, float y1, float x2, float y2, QRgb color)
{
    float dx, dy, x, y, x_inc, y_inc;
    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    int i;
    int length;
    if (abs(dx) >= abs(dy))
        length = abs(dx);
    else
        length = abs(dy);
    image_1.setPixel(x, y, color);
    x_inc = dx / length;
    y_inc = dy / length;
    for(i = 0; i < length; i++)
    {
        x = x + x_inc;
        y = y + y_inc;
        image_1.setPixel(x, y, color);
//        cout<<"X "<<x<<endl;
//        cout<<"Y "<<y<<endl;
    }
    ui->label_2->setPixmap(QPixmap::fromImage(image_1));
}


void MainWindow:: getcode(int a[], float x, float y)
{
    if(x < 100)
    {
        a[3] = 1;
    }
    else if(x > 300)
    {
        a[2] = 1;
    }
    if(y < 100)
    {
        a[0] = 1;
    }
    else if(y > 300)
    {
        a[1] = 1;
    }
}

void MainWindow:: clip(float x1, float y1, float x2, float y2)
{
    float x_1 = x1, y_1 = y1, x_2 = x2, y_2 = y2, m;
    int outcode[4] = {0, 0, 0, 0};
    int outcode_1[4] = {0, 0, 0, 0};
    getcode(outcode,x1, y1);
    getcode(outcode_1, x2, y2);
    cout<<outcode[0]<<outcode[1]<<outcode[2]<<outcode[3]<<endl;
    cout<<outcode_1[0]<<outcode_1[1]<<outcode_1[2]<<outcode_1[3]<<endl;
    m = (y2 - y1)/(x2 - x1);
    if(((outcode[0] | outcode_1[0]) == 0) & ((outcode[1] | outcode_1[1]) == 0) & ((outcode[2] | outcode_1[2]) == 0) & ((outcode[3] | outcode_1[3]) == 0))
    {
        dda_algo_1(x1, y1, x2, y2, color);
        cout<<"Not clipped"<<endl;
        return;
    }
    else
    {
        if (outcode[3] == 1)
        {
            //ok
            x_1 = 100;
            y_1 = ((100 - x2)*m) + y2;
//            dda_algo_1(x_1, y_1, x_2, y_2, color);
        }
        if(outcode[2] == 1)
        {
            //ok
            x_1 = 300;
            y_1 = (300 - x2)*m + y2;
//            dda_algo_1(x_1, y_1, x_2, y_2,color);
        }
        if(outcode[1] == 1)
        {
            //ok
            x_1 = ((300 - y_2)/m) + x_2;
            y_1 = 300;
//            dda_algo_1(x_1, y_1, x_2, y_2,color);
        }
        if(outcode[0] == 1)
        {
            //ok
            y_1 = 100;
            x_1 = ((100 - y2)/m) + x2;
//            dda_algo_1(x_1, 100, x_2, y_2,color);
        }
        if(outcode_1[3] == 1)
        {
            //ok
            x_2 = 100;
            y_2 = ((100 - x_1)*m) + y_1;
//            dda_algo_1(x_1, y_1, x_2, y_2,color);
        }
        if(outcode_1[2] == 1)
        {
            //ok
            x_2 = 300;
            y_2 = ((300 - x_1)* m) + y_1;
//            dda_algo_1(x_1, y_1, x_2, y_2,color);
        }
        if(outcode_1[1] == 1)
        {
            //ok
            y_2 = 300;
            x_2 = ((300 - y_1)/m) + x_1;
//            dda_algo_1(x_1, y_1, x_2, y_2, color);
        }
        if(outcode_1[0] == 1)
        {
            //ok
            y_2 = 100;
            x_2 = ((100 - y_1)/m) + x_1;
//            dda_algo_1(x_1, y_1, x_2, y_2,color);
        }
        dda_algo_1(x_1, y_1, x_2, y_2,color);
    }
    ui->label_2->setPixmap(QPixmap::fromImage(image_1));
}


void MainWindow::on_pushButton_2_clicked()
{
    dda_algo(100,100,300,100,color);
    dda_algo(100,100,100,300,color);
    dda_algo(300,300,100,300,color);
    dda_algo(300,300,300,100,color);
    int x1, y1, x2, y2;
    x1 = ui->textEdit->toPlainText().toFloat();
    y1 = ui->textEdit_2->toPlainText().toFloat();
    x2 = ui->textEdit_3->toPlainText().toFloat();
    y2 = ui->textEdit_4->toPlainText().toFloat();
    dda_algo(x1,y1,x2,y2,color);
}


void MainWindow::on_pushButton_3_clicked()
{
    dda_algo_1(100,100,300,100,color);
    dda_algo_1(100,100,100,300,color);
    dda_algo_1(300,300,100,300,color);
    dda_algo_1(300,300,300,100,color);
    float x1, y1, x2, y2;
    x1 = ui->textEdit->toPlainText().toFloat();
    y1 = ui->textEdit_2->toPlainText().toFloat();
    x2 = ui->textEdit_3->toPlainText().toFloat();
    y2 = ui->textEdit_4->toPlainText().toFloat();
//    dda_algo_1(x1,y1,x2,y2,qRgb(255,255,255));
    clip(x1,y1,x2,y2);
}

