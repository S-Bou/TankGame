#include "losewintext.h"

LoseWinText::LoseWinText(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{

}

void LoseWinText::ShowLose()
{
    setPlainText("YOU LOSE");
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 36, 75, false));
    setPos(280, 20);
}

void LoseWinText::ShowWin()
{
    setPlainText("YOU WIN");
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 36, 75, false));
    setPos(280, 20);
}


