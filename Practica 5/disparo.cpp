#include "disparo.h"

Disparo::Disparo(int direccion)
    : direccion(direccion)
{
    // Configura la posición inicial del disparo según la dirección actual del sprite
    int velocidad = 5;
    switch (direccion) {
    case 0: // Abajo
        setPos(x(), y() + velocidad);
        break;
    case 100: // Derecha
        setPos(x() + velocidad, y());
        break;
    case 200: // Arriba
        setPos(x(), y() - velocidad);
        break;
    case 300: // Izquierda
        setPos(x() - velocidad, y());
        break;
    default:
        break;
    }
}

QRectF Disparo::boundingRect() const
{
    return QRectF(0, 0, 10, 10); // Devuelve el rectángulo delimitador del disparo
}

void Disparo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); // Para evitar el warning de parámetro no utilizado

    painter->setBrush(Qt::red); // Establece el color del pincel para el disparo
    painter->drawRect(boundingRect()); // Dibuja el disparo
}
