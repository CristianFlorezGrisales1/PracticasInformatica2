#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, ancho, alto)),
    Donald(new sprite())
{
    ui->setupUi(this);

    QRect Desktop = QGuiApplication::primaryScreen()->geometry();
    x = Desktop.x();
    y = Desktop.y();
    ancho = Desktop.width() - 100;
    alto = Desktop.height() - 100;

    ui->graphicsView->setScene(scene);

    // Añade el sprite a la escena
    scene->addItem(Donald);
    Donald->setPos(200, 700);

    // No necesitas crear un proyectil aquí, lo crearemos en mousePressEvent
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // Funciones de teclas

    if (event->key() == Qt::Key_D && Donald->x() < ancho - Donald->boundingRect().width()) {
        Donald->cambiarFlecha(100); // Derecha
    }

    if (event->key() == Qt::Key_A && Donald->x() > 0) {
        Donald->cambiarFlecha(300); // Izquierda
    }

    if (event->key() == Qt::Key_W && Donald->y() > 0) {
        Donald->cambiarFlecha(200); // Arriba
    }

    if (event->key() == Qt::Key_S && Donald->y() < alto - Donald->boundingRect().height()) {
        Donald->cambiarFlecha(0); // Abajo
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // Obtén la posición actual de Donald
        QPointF donaldPos = Donald->pos();

        // Calcula la dirección basada en la posición del mouse y la posición de Donald
        int direction;
        if (event->x() > donaldPos.x()) {
            // Mouse a la derecha de Donald
            direction = 3; // Derecha
        } else if (event->x() < donaldPos.x()) {
            // Mouse a la izquierda de Donald
            direction = 2; // Izquierda
        } else if (event->y() < donaldPos.y()) {
            // Mouse arriba de Donald
            direction = 1; // Arriba
        } else {
            // Mouse abajo de Donald
            direction = 0; // Abajo
        }

        // Crea un proyectil con la dirección calculada
        Proyectil *disparo = new Proyectil(direction);
        scene->addItem(disparo);

        // Posiciona el proyectil en la posición actual de Donald
        disparo->setPos(donaldPos);

        // Otras configuraciones según sea necesario
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


