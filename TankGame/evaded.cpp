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
}

void Evaded::DecreaseEvaded()
{
    //If evade 4 or more enemies
    if(evaded <= 0)
    {
        //qDebug() << "Se han evadido 4";
        evaded = 0;
        setPlainText("Lives: " + QString::number(evaded));
        game->ResetGameLose();
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

