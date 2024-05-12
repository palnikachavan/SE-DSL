#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QApplication>
#include <QColor>
#include <QColorDialog>
#include <QImage>

QImage image(400, 400, QImage::Format_RGB888);
QColor col1;
QRgb color;
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
    float x = x1, y = y1, dx, dy, x_inc, y_inc;
    dx = x2 - x1;
    dy = y2 - y1;
    int length, i;
    if (abs(dx) >= abs(dy))
        length = abs(dx);
    else
        length = abs(dy);
    x_inc = dx / length;
    y_inc = dy / length;
    image.setPixel(x, y, color);
    for(i = 0; i < length;i++)
    {
        x = x + x_inc;
        y = y + y_inc;
        image.setPixel(x, y, color);
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow ::translate(float x1, float y1, float x2, float y2, QRgb color)
{
    float tx, ty;
    tx = ui->textEdit->toPlainText().toFloat();
    ty = ui->textEdit_2->toPlainText().toFloat();
    dda_algo(x1 + tx, y1 - ty, x2 + tx, y2 - ty, color);
}

void MainWindow ::scale(float x1, float y1, float x2, float y2, QRgb color)
{
    float sx, sy;
    sx = ui->textEdit_3->toPlainText().toFloat();
    sy = ui->textEdit_4->toPlainText().toFloat();
    dda_algo((sx*(x1 - 200)) +200, (sy*(y1 - 200)) + 200, (sx*(x2 - 200)) +200, (sy*(y2 - 200)) + 200, color);
}

void MainWindow:: rotate(float x1, float y1, float x2, float y2, QRgb color)
{
    float r, s, c, a,b;
    r = ui->textEdit_5->toPlainText().toFloat();
    float theta = -r/57.2958;   //degrees to radian
    s = sin(theta);
    c = cos(theta);
    a = -200*c + 200*s + 200;
    b = - 200*s - 200*c + 200;
    dda_algo((x1*c - y1*s +a),(x1*s + y1*c + b),(x2*c - y2*s +a),(x2*s + y2*c + b),color );
}

void MainWindow::on_pushButton_clicked()
{
    //co ordinate axes static
    dda_algo(200,0,199,399,qRgb(255,255,255));
    dda_algo(0,200,399,199,qRgb(255,255,255));

    // initial object
    dda_algo(280,100,200,200,qRgb(255,255,255));
    dda_algo(200,200,350,180,qRgb(255,255,255));
    dda_algo(280,100,350,180,qRgb(255,255,255));
}

void MainWindow::on_pushButton_2_clicked()
{
    // translate
    translate(200,200,280,100,color);
    translate(200,200,350,180,color);
    translate(280,100,350,180,color);
}


void MainWindow::on_pushButton_4_clicked()
{
    // get Color
    col1 = QColorDialog::getColor();
    color = col1.rgb();
}

void MainWindow::on_pushButton_3_clicked()
{
    //scale
    scale(200,200,280,100,color);
    scale(200,200,350,180,color);
    scale(280,100,350,180,color);
}



void MainWindow::on_pushButton_5_clicked()
{
    rotate(200,200,280,100,color);
    rotate(200,200,350,180,color);
    rotate(280,100,350,180,color);
}

