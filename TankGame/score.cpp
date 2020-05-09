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

    //Config sonund for when player win
    soundWin = new QMediaPlayer();
    soundWin->setMedia(QUrl("qrc:/sounds/winSound.wav"));
}

void Score::IncreaseScore() //Setter
{
    if(score >= 10)
    {
        //qDebug() << "10 enemigos destruidos";
        setPlainText("Score: " + QString::number(10));
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

int Score::getScore() const
{
    return score;
}

void Score::SoundWin()
{
    soundWin->play();
}



