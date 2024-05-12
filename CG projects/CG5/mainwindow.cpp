#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QColor>
#include <QApplication>
#include <QColorDialog>
#include <math.h>

QColor col1;
QRgb color;
QImage image(600, 600, QImage::Format_RGB888);
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
    int it = ui->textEdit->toPlainText().toInt();
    snowflake(it, 500, 400, 100, 400);
    snowflake(it, 300, 54, 500, 400);
    snowflake(it, 100, 400, 300, 54);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow ::dda_line(float x1, float y1, float x2, float y2, QRgb color)
{
    float dx, dy, x, y;
    int length, i;
    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;
    image.setPixel(x, y, color);
    if (abs(x) >= abs(dy))
    {
        length = abs(x);
    }
    else
    {
        length = abs(dy);
    }
    float x_inc, y_inc;
    x_inc = dx / length;
    y_inc = dy / length;
    for (i = 0; i < length; i++)
    {
        x = x + x_inc;
        y = y + y_inc;
        image.setPixel(x, y, color);
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}


void MainWindow :: snowflake(int it, float x1, float y1, float x2, float y2)
{
    if (it == 0)
    {
        dda_line(x1, y1, x2, y2, color);
        return;
    }
    float tripleX = (x2 - x1)/3;
    float tripleY = (y2 - y1)/3;
    float x13 = x1 + tripleX;
    float y13 = y1 + tripleY;
    float x16 = x1+2*tripleX;
    float y16 = y1+2*tripleY;
//    float x145 = x13+(x16-x13)/2+(y16-y13)*sqrt(3)/2; // these equations are important
//    float y145 = y13-(x16-x13)*sqrt(3)/2+(y16-y13)/2;
    float x145 = x13 + ((x16 - x13)/2) + ((y16 - y13)*sqrt(3))/2;
    float y145 = y13 - (((x16 - x13)*sqrt(3))/2) + (y16 - y13)/2;

    /* x -> initial x + (diff of x)*cos60 + (diff of y)*sin60
       y -> initial y - (diff of x)*sin60 + (diff of y)*cos60*/
    snowflake(it-1,x1,y1,x13,y13);
    snowflake(it-1,x13,y13,x145,y145);
    snowflake(it-1,x145,y145,x16,y16);
    snowflake(it-1,x16,y16,x2,y2);

}

void MainWindow::on_pushButton_2_clicked()
{
    col1 = QColorDialog::getColor();
    color = col1.rgb();

}

