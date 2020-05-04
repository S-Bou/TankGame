#include "player.h"
#include "shot.h"

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/playerTank.png"));
    setTransformOriginPoint(50, 50);
    rotacion = 0;

    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/Disparo.mp3"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        if(rotacion <= -360){rotacion = 0;}
            rotacion -= 45;
            setRotation(rotacion);
    }
    else if(event->key() == Qt::Key_D)
    {
        if(rotacion >= 360){rotacion = 0;}
            rotacion += 45;
            setRotation(rotacion);
    }
    else if(event->key() == Qt::Key_W)
    {
        if(pos().x() >= 0       && pos().y() >= 0 &&
           pos().x()+100 <= 800 && pos().y()+100 <= 600)
           SetDireccionTank(rotacion);

        //Para que no se salga de la vista
        if(pos().x() <= 0)setPos(x()+10, y());
        if(pos().x()+100 >= 800)setPos(x()-10, y());
        if(pos().y() <= 0)setPos(x(), y()+10);
        if(pos().y()+100 >= 600)setPos(x(), y()-10);

    }
    else if(event->key() == Qt::Key_S)
    {
        if(pos().x() >= 0       && pos().y() >= 0 &&
           pos().x()+100 <= 800 && pos().y()+100 <= 600)
           SetDireccionTank(rotacion-180);

        //Para que no se salga de la vista
        if(pos().x() <= 0)setPos(x()+10, y());
        if(pos().x()+100 >= 800)setPos(x()-10, y());
        if(pos().y() <= 0)setPos(x(), y()+10);
        if(pos().y()+100 >= 600)setPos(x(), y()-10);
    }
    else if(event->key() == Qt::Key_Space)
    {
        Shot *shot = new Shot(this);
        shot->setPos(x()+40, y()+40);
        scene()->addItem(shot);

        //Play bullet sound
        if(bulletsound->state() == QMediaPlayer::PlayingState)
        {bulletsound->setPosition(0);}
        else if(bulletsound->state() == QMediaPlayer::StoppedState)
        {bulletsound->play();}
  }
}

void Player::SetDireccionTank(int direccion)
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
}

void Player::spawnEnemy(void)
{
    enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::DeleteEnemies()
{
    //delete enemy;
    enemy->hide();
}

int Player::getRotacion(void)
{
    return rotacion;
}
