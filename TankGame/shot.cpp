#include "shot.h"

Shot::Shot(Player *p): QObject(), QGraphicsPixmapItem()
{
    jugador = p;
    setPixmap(QPixmap(":/images/shot.png"));

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}

void Shot::move()
{
    int rotacion = jugador->getRotacion();

    if     (rotacion ==    0){setPos(x()   , y()-10);}
    else if(rotacion ==  -45){setPos(x()-10, y()-10);}
    else if(rotacion ==  -90){setPos(x()-10,    y());}
    else if(rotacion == -135){setPos(x()-10, y()+10);}
    else if(rotacion == -180){setPos(x()   , y()+10);}
    else if(rotacion == -225){setPos(x()+10, y()+10);}
    else if(rotacion == -270){setPos(x()+10,    y());}
    else if(rotacion == -315){setPos(x()+10, y()-10);}
    else if(rotacion == -360){setPos(x()   , y()-10);}
    else if(rotacion ==   45){setPos(x()+10, y()-10);}

    //Delete shot when exit of view
    if(pos().y()+10 < 0)
    {
        scene()->removeItem(this);
        delete this;
        jugador->setShotState(false);
        qDebug() << "Bullet up deleted";
    }
    else if(pos().x()+10 < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet left deleted";
    }
    else if(pos().y()+10 > 800)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet down deleted";
    }
    else if(pos().x()+10 > 600)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet right deleted";
    }
}
