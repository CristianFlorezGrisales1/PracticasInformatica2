// Proyectil.cpp

#include "Proyectil.h"

Proyectil::Proyectil(int direction, QObject *parent) : QObject(parent), direction(direction)
{
    setFlag(ItemIsSelectable);

    // Configura un temporizador para mover el proyectil
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Proyectil::mover);
    timer->start(50);  // Ajusta la velocidad del proyectil según sea necesario
}

QRectF Proyectil::boundingRect() const
{
    return QRectF(0, 0, 10, 10);  // Ajusta el tamaño del proyectil según sea necesario
}

void Proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkRed);  // Ajusta el color del proyectil según sea necesario
    painter->drawEllipse(boundingRect());
}

void Proyectil::mover()
{
    // Actualiza la posición del proyectil en la dirección correspondiente
    switch (direction) {
    case 0: // Abajo
        setPos(mapToParent(0, velocidad));
        break;
    case 1: // Arriba
        setPos(mapToParent(0, -velocidad));
        break;
    case 2: // Izquierda
        setPos(mapToParent(-velocidad, 0));
        break;
    case 3: // Derecha
        setPos(mapToParent(velocidad, 0));
        break;
    default:
        break;
    }

    // Emite la señal de proyectil disparado con la nueva posición
    emit proyectilDisparado(pos());

}
