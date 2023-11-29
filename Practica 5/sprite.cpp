#include "sprite.h"

sprite::sprite(QObject *parent)
    : QObject{parent}
{
    timer=new QTimer();

    filas=300;
    columnas=0;
    pixmap = new QPixmap("D:/Descargas/PracticaMovimiento0_1/Picture/priteDonalTrump.png");


    //dimension de cada una de las imagenes

    ancho=100;
    alto= 100;

    timer->start(100);

    connect(timer,&QTimer::timeout,this,&sprite::Actualizacion);


}

void sprite::cambiarFlecha(int numero)
{


    switch (numero) {
    case 0: // Abajo
        tecla=numero;
        setPos(x(), y() + velocidad);
        break;
    case 100: // Derecha
        setPos(x() + velocidad, y());
        tecla=numero;
        break;
    case 200: // Arriba
        setPos(x(), y() - velocidad);
        tecla=numero;
        break;
    case 300: // Izquierda
        setPos(x() - velocidad, y());
        tecla=numero;
        break;
    default:
        break;
    }


}

void sprite::Actualizacion()
{
    columnas+=100;
    if(columnas>=600){
        columnas=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}


QRectF sprite::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); // Para evitar el warning de parámetro no utilizado

    if (widget) {
        painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas,  tecla, ancho, alto);
    }
}
