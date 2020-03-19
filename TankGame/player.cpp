#include "player.h"
#include "shot.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPoint>
#include <QDebug>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/playerTank.png"));
    setTransformOriginPoint(50, 50);
    rotacion = 0;
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
        rotacion -= 45;
        setRotation(rotacion);
    }
    else if(event->key() == Qt::Key_E)
    {
        if(rotacion >= 360){rotacion = 0;}
        rotacion += 45;
        setRotation(rotacion);
    }
    else if(event->key() == Qt::Key_Space)
    {
        Shot *shot = new Shot(this);
        shot->setPos(x()+40, y()+40);
        scene()->addItem(shot);
    }
}

int Player::getRotacion(void)
{
    return rotacion;
}