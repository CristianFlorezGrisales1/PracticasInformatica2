#ifndef DISPARO_H
#define DISPARO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class Disparo : public QGraphicsItem
{
    Q_OBJECT
public:
    Disparo(int direccion);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public slots:
    void mover();

private:
    int direccion;
    QTimer *timer;
};

#endif // DISPARO_H
