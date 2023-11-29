#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGuiApplication>
#include<QGraphicsItem>
#include<QRectF>
#include<QDebug>
#include<QScreen>
#include<QPainter>
#include<QGraphicsScene>
#include <QKeyEvent> // Captura de teclas

#include"sprite.h"
#include"proyectil.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent *event); //método sobrecargado

    void mousePressEvent(QMouseEvent *event);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    sprite *Donald;

    float x,y,ancho,alto;

};
#endif // MAINWINDOW_H
