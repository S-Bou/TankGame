#include "enemy.h"
#include "game.h"
#include <QPoint>

extern Game *game;

Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{
    //Define with random position where spawn enemy
    int PosX =  RandomHandler(100, 600);
    int PosY =  RandomHandler(100, 400);
    //qDebug() << PosX << ", " << PosY;
    setPos(PosX,PosY);
    int dir[] = {0, -45, -90, -135, -180, -225, -270, -315, -360,
                     45,  90,  135,  180,  225,  270,  315,  360};
    //Define with random direction of enemy
    direccion = dir[qrand() % 16];

    setRotation(direccion);
    setPixmap(QPixmap(":/images/enemyTank.png"));

    //Timer that define time between spawns
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(moveEnemy()));
    timer->start(200);
}

int Enemy::RandomHandler(int lowest, int highest)
{
    uint aux = (int)QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();
    qsrand(aux);
    return (qrand() % (highest - lowest)) + lowest;
}

Enemy::~Enemy()
{
    delete timer;
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
        game->evaded->DecreaseEvaded();
        scene()->removeItem(this);
        delete this;
    }
    else if(pos().x()+100 < 0)
    {
        game->evaded->DecreaseEvaded();
        scene()->removeItem(this);
        delete this;
    }
    else if(pos().y()+100 > 800)
    {
        game->evaded->DecreaseEvaded();
        scene()->removeItem(this);
        delete this;
    }
    else if(pos().x()+100 > 1000)
    {
        game->evaded->DecreaseEvaded();
        scene()->removeItem(this);
        delete this;
    }
}
