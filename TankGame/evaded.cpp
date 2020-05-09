#include "evaded.h"
#include "game.h"

extern Game *game;

Evaded::Evaded(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //Initialize the score to 0
    evaded = 4;
    //Draw the text
    setPlainText("Lives: " + QString::number(evaded));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times", 24));

    //Confic sonund for when player lose
    soundLose = new QMediaPlayer();
    soundLose->setMedia(QUrl("qrc:/sounds/loseSound.wav"));
}

void Evaded::DecreaseEvaded() //Setter
{
    //If evade 4 or more enemies
    if(evaded <= 0)
    {
        //qDebug() << "Se han evadido 4";
        setPlainText("Lives: " + QString::number(0));
    }
    else
    {
        evaded--;
        setPlainText("Lives: " + QString::number(evaded));
    }
}

void Evaded::ResetLives()
{
    evaded = 4;
    setPlainText("Lives: " + QString::number(evaded));
}

void Evaded::SoundLose()
{
    soundLose->play();
}

int Evaded::getEvaded() const
{
    return evaded;
}

