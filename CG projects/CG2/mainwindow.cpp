#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QApplication>
#include <iostream>
#include <QColor>
#include <QColorDialog>
#include <QMouseEvent>

using namespace std;
// mouse click
int X[50];
int Y[50];
bool start = true;
int ver = -1;

//scanline
float slope[25], dx, dy;
float xi[20];

// select color
QColor col;
QRgb color;

QImage image(500,500,QImage::Format_RGB888);
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
    float dx, dy;
    dx = x2 - x1;
    dy = y2 - y1;
    int len;
    if (abs(dx) > abs(dy))
        len = abs(dx);
    else
        len = abs(dy);
    float x_inc, y_inc, x , y;
    x_inc = dx / len;
    y_inc = dy / len;
    x = x1;
    y = y1;
    image.setPixel(x1, y1, color);
    int i;
    for(i = 0; i < len; i++)
    {
        x = x + x_inc;
        y = y + y_inc;
        image.setPixel(x, y, color);
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x, y;
    x = event->pos().x();
    y = event->pos().y();
    if(start)
    {
        if (event->button() == Qt::RightButton)
        {
            dda_algo(X[0], Y[0], X[ver], Y[ver], color);
            start = false;
            return;
        }
        else if(ver == -1)
        {
            ver++;
            X[ver] = x;
            Y[ver] = y;
        }
        else
        {
            ver++;
            X[ver] = x;
            Y[ver] = y;
            dda_algo(X[ver - 1], Y[ver - 1], X[ver], Y[ver], color);
        }

    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_2_clicked()
{
    col = QColorDialog::getColor();
    color = col.rgb();
}

//int MainWindow::sort(int arr[], int n)
//{
//    int key, j;
//    for(int i=1; i<n; i++)
//    {
//        key = arr[i];
//        j = j - 1;

//        while(j >= 0 && arr[j] > key)
//        {
//            arr[j+1] = arr[j];
//            j = j - 1;
//        }
//        arr[j+1] = key;
//    }
//    return arr[10];
//}



//void MainWindow::scanline()
//{
//    float dx,dy, xi[50],temp;
//    int k;
//    float slope[20];
//    ver++;

//    // adding initial point to X and Y arrays
//    X[ver] = X[0];
//    Y[ver] = Y[0];

//    // calculation of slope array -->  1 / slope
//    for(int i=0;i<=ver;i++)
//    {
//        //pairs of points
//        dy = Y[i+1]-Y[i];
//        dx = X[i+1] - X[i];
//        if(dy == 0.0f) {
//            slope[i]=0.0;}
//        if(dx  == 0.0f) {
//            slope[i]=0.0;}
//        if((dy != 0.0f) && (dx != 0.0f))
//        {
//            slope[i] = dx/dy;
//        }
//    }

//    //scanning wrt y
//    for(int y=0;y<500;y++)
//    {
//        k = 0;
//        for(int i=0;i<ver;i++)
//        {
//            // creating xi array which contains x co ords of active edges
//            if(((Y[i]<=y)&&(Y[i+1]>y)) || ((Y[i]>y)&&(Y[i+1]<=y)))
//            {
//                xi[k] = X[i] + (slope[i]*(y-Y[i]));
//                k++;
//            }
//        }

//        // sorting x1 array
//        // bubble sort
//        for(int j=0;j<k-1;j++)
//        {
//            for(int i=0;i<k-j-1;i++)
//            {
//                if(xi[i]>xi[i+1])
//                {
//                    temp = xi[i] ;
//                    xi[i]=xi[i+1];
//                    xi[i+1]=temp;

//                }
//            }
//        }
//        //plotting using xi points in pairs and y
//        for(int i=0;i<k;i+=2)
//        {
//            dda_algo(xi[i+1],y,xi[i],y,color);
//        }
//    }
//    ui->label->setPixmap(QPixmap::fromImage(image));

//}

void MainWindow::on_pushButton_clicked()
{
    scanline();
}

void MainWindow:: scanline()
{
    ver++;
    X[ver] = X[0];
    Y[ver] = Y[ver];
    float dx, dy, slope[20],xi[50], temp;
    int i, j, k = 0;


    for(i = 0 ;i <= ver; i++)
    {
        dx = X[i + 1] - X[i];
        dy = Y[i + 1] - Y[i];
        if(dx == 0.0f)
            slope[i] = 1.0;
        if(dy == 0.0f)
            slope[i] = 0.0;
        if(dx != 0.0f && dy != 0.0f)
            slope[i] = dx / dy;
     }

    for(int y = 0; y < 500; y++)
    {
        k = 0;
        //init xi
        for(i = 0; i < ver; i++)
        {
            if(((Y[i] <= y) && (Y[i + 1] > y)) || ((Y[i + 1] <= y) && (Y[i] > y)))
            {
                xi[k] = X[i] + ((y - Y[i])*slope[i]);
                k++;
            }
        }

        // sort
        for(j = 0; j < k-1; j++)
        {
            for(i = 0; i < k - j - 1;i++)
            {
                if(xi[i] > xi[i + 1])
                {
                    temp = xi[i];
                    xi[i] = xi [i + 1];
                    xi [i + 1] = temp;
                }
            }
        }
        // plot
        for(i = 0; i < k - 1; i+= 2)
        {
            dda_algo(xi[i], y, xi[i+1],y,color);
        }
    }
}




































