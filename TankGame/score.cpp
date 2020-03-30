#include "score.h"

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //Initialize the score to 0
    score = 0;
    //Draw the text
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 24));
}

void Score::IncreaseScore()
{
    score++;
    setPlainText("Score: " + QString::number(score));
}

