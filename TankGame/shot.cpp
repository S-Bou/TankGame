#include "shot.h"

Shot::Shot(Player *p): QObject(), QGraphicsPixmapItem()
{
    jugador = p;
    direccion = jugador->getRotacion();
    setPixmap(QPixmap(":/images/shot.png"));

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Shot::move()
{

    if     (direccion ==    0){setPos(x()   , y()-10);}
    else if(direccion ==  -45){setPos(x()-10, y()-10);}
    else if(direccion ==  -90){setPos(x()-10,    y());}
    else if(direccion == -135){setPos(x()-10, y()+10);}
    else if(direccion == -180){setPos(x()   , y()+10);}
    else if(direccion == -225){setPos(x()+10, y()+10);}
    else if(direccion == -270){setPos(x()+10,    y());}
    else if(direccion == -315){setPos(x()+10, y()-10);}
    else if(direccion == -360){setPos(x()   , y()-10);}
    else if(direccion ==   45){setPos(x()+10, y()-10);}

    //Delete shot when exit of view
    if(pos().y()+10 < 0)
    {
        scene()->removeItem(this);
        delete this;
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
