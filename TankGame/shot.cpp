#include "shot.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

Shot::Shot()
{

    //Drew the rect (bullet)
    setRect(0,0,10,50);
    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Shot::move(void)
{
    int rotacion = setRotacion();

    qDebug() << rotacion;
    setPos(x(), y()-10);

    if     (rotacion == -45){setPos(x()-10, y()-10);}
    else if(rotacion == 135){setPos(x()+10, y()+20);}

    //Delete shot when exit of view
    if(pos().y()+rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
        //qDebug() << "Bullet deleted";
    }
}
