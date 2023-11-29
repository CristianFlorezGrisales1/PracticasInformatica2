#ifndef SPRITE_H
#define SPRITE_H

#include<QGraphicsItem>
#include<QWindow>
#include<QTimer>
#include<QPixmap>
#include <QObject>
#include<QPainter>
#include <QStyleOptionGraphicsItem>


class sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit sprite(QObject *parent = nullptr);

    int tecla=0;
    int velocidad = 10;

    QTimer *timer;
    QPixmap *pixmap;

    float filas,columnas,ancho,alto;

    void cambiarFlecha(int numero);

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

signals:
public slots:
    void Actualizacion();

};

#endif // SPRITE_H
