// proyectil.cpp
#include "proyectiles.h"

Proyectiles::Proyectiles(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap("proyectil.png")); // Ajusta el nombre de tu archivo de imagen

    velocidad = 10; // Puedes ajustar la velocidad según tus necesidades

    // Configurar el temporizador para el movimiento del proyectil
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(mover()));
    timer->start(30); // Ajusta el intervalo del temporizador según tus necesidades
}

void Proyectiles::disparar()
{
    setPos(x() + pixmap().width() / 2, y()); // Ajusta la posición inicial del proyectil
}

void Proyectiles::mover()
{
    setPos(x(), y() - velocidad); // Mover el proyectil hacia arriba

    // Si el proyectil sale de la escena, eliminarlo
    if (pos().y() + pixmap().height() < 0) {
        delete this;
    }
}
