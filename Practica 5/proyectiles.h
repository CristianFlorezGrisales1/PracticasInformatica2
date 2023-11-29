// proyectil.h
#ifndef PROYECTILES_H
#define PROYECTILES_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Proyectiles : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Proyectiles(QGraphicsItem* parent = nullptr);

    void disparar();

    QTimer* timer;

    int velocidad;


public slots:
    void mover();


};

#endif // PROYECTIL_H
