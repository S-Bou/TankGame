#include "shot.h"

extern Game *game;

Shot::Shot(Player *p): QObject(), QGraphicsPixmapItem()
{
    jugador = p;
    direccion = jugador->getRotacion();
    setPixmap(QPixmap(":/images/shot.png"));

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(moveShotPlayer()));
    timer->start(50);
}

Shot::~Shot()
{

}

void Shot::moveShotPlayer(void)
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

    //Delete shot when exit of view
    if(pos().y()+10 < 0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    else if(pos().x()+10 < 0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    else if(pos().y()+10 > 600)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    else if(pos().x()+10 > 800)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

    //When shot collides with enemy destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            if(game->score->getScore() >= 10)
            {
                timer->stop();
            }

            //Increase the score
            game->score->IncreaseScore();
            //Remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //Delete them both
            delete colliding_items[i];
            delete this;
            //All code below refers to a non existint bullet
            return;
        }
    }


}

void Shot::StopShot(void)
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveShotPlayer()));
}


