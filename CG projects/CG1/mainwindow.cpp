#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QColor>
QImage image(400, 400, QImage::Format_RGB888);
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

void MainWindow:: dda_algo(float x1, float y1, float x2, float y2, QRgb color)
{
    float dx, dy, length;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx) >= abs(dy))
    {
        length = dx;
    }
    else
    {
        length = dy;
    }
    float x_inc, y_inc, x = x1, y = y1;
    image.setPixel(x1, y1, color);
    int i;
    x_inc = dx / length;
    y_inc = dy / length;
    for(i = 0; i < length; i++)
    {
        x += x_inc;
        y += y_inc;
        image.setPixel(x, y, color);
    }
    ui->label->setPixmap(QPixmap::fromImage(image));

}

void points_8(float x, float y, float xc, float yc)
{
    image.setPixel(x + xc, y + yc, qRgb(255,255,0));
    image.setPixel(-x + xc, -y + yc, qRgb(255,255,0));
    image.setPixel(-x + xc, y + yc, qRgb(255,255,0));
    image.setPixel(x + xc, -y + yc, qRgb(255,255,0));
    image.setPixel(xc + y, yc + x, qRgb(255,255,0));
    image.setPixel(xc - y, yc - x, qRgb(255,255,0));
    image.setPixel(xc - y, yc + x, qRgb(255,255,0));
    image.setPixel(xc + y, yc - x, qRgb(255,255,0));
}

void MainWindow:: bresenham_circle(float xc, float yc, int r)
{
    float d;
    float x = 0, y = r;
    points_8(x,y,xc,yc);
    d = 3 - 2 * r;
    while(y>=x)
    {
        x++;
        if(d >= 0)
        {
            d = d + 4*(x - y) + 10;
            y --;
        }
        else
        {
            d = d + 4 * x + 6;
        }
        points_8(x,y,xc,yc);

    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}




void MainWindow::on_pushButton_clicked()
{
    bresenham_circle(150,150,100);
    bresenham_circle(150,150,50);
    dda_algo(150,150,63.3,200,qRgb(255,255,0));
    dda_algo(150,50,236.6,200,qRgb(255,255,0));
    dda_algo(150,50,63.397,200,qRgb(255,255,0));
    dda_algo(63.397,200,236.6,200,qRgb(255,255,0));
}
