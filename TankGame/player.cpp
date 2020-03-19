#include "player.h"
#include "shot.h"

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/playerTank.png"));
    setTransformOriginPoint(50, 50);
    rotacion = 0;
    shotActive=false;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        if(pos().x() > 0)
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_D)
    {
        if(pos().x()+100 < 800)
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_W)
    {
        if(pos().y() > 0)
        setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_S)
    {
        if(pos().y()+100 < 600)
        setPos(x(),y()+10);
    }
    else if(event->key() == Qt::Key_Q)
    {
        if(rotacion <= -360){rotacion = 0;}
        if(!shotActive)
        {
            rotacion -= 45;
            setRotation(rotacion);
        }
    }
    else if(event->key() == Qt::Key_E)
    {
        if(rotacion >= 360){rotacion = 0;}
        if(!shotActive)
        {
            rotacion += 45;
            setRotation(rotacion);
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        Shot *shot = new Shot(this);
        shot->setPos(x()+40, y()+40);
        scene()->addItem(shot);
        setShotState(true);
    }
}

int Player::getRotacion(void)
{
    return rotacion;
}

void Player::setShotState(bool data)
{
    shotActive = data;
}

bool Player::getShotState()
{
    return shotActive;
}
