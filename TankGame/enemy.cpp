#include "enemy.h"
#include "player.h"
#include <QPoint>

Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{
    int PosX =  rand() % 600 + 100;
    int PosY =  rand() % 400 + 100;
    setPos(PosX,PosY);
    int dir[] = {0, -45, -90, -135, -180, -225, -270, -315, -360,
                     45,  90,  135,  180,  225,  270,  315,  360};
    direccion = dir[rand() % 16];
    setRotation(direccion);
    setPixmap(QPixmap(":/images/enemyTank.png"));

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(moveEnemy()));
    timer->start(200);
}

void Enemy::moveEnemy()
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
    else if(direccion ==   90){setPos(x()+10,    y());}
    else if(direccion ==  135){setPos(x()+10, y()+10);}
    else if(direccion ==  180){setPos(x()   , y()+10);}
    else if(direccion ==  225){setPos(x()-10, y()+10);}
    else if(direccion ==  270){setPos(x()-10,    y());}
    else if(direccion ==  315){setPos(x()-10, y()-10);}
    else if(direccion ==  360){setPos(x()   , y()-10);}

    //Delete enemy when exit of view
    if     (pos().y()+100 < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
    else if(pos().x()+100 < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
    else if(pos().y()+100 > 800)
    {
        scene()->removeItem(this);
        delete this;
    }
    else if(pos().x()+100 > 1000)
    {
        scene()->removeItem(this);
        delete this;
    }
}
