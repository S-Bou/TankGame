#include "evaded.h"

Evaded::Evaded(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //Initialize the score to 0
    evaded = 5;
    //Draw the text
    setPlainText("Score: " + QString::number(evaded));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times", 24));
}

void Evaded::DecreaseEvaded()
{
    if(evaded == 0){evaded = 5;}
    evaded--;
    setPlainText("Score: " + QString::number(evaded));
}

