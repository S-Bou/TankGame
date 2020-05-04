#include "score.h"
#include "game.h"

extern Game *game;

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
    if(score >= 10)
    {
        qDebug() << "10 enemigos destruidos";

        game->ResetGameWin();
    }
    else
    {
        score++;
        setPlainText("Score: " + QString::number(score));
    }
}

void Score::ResetScore()
{
    score = 0;
    setPlainText("Score: " + QString::number(score));
}



