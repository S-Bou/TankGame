#ifndef LOSEWINTEXT_H
#define LOSEWINTEXT_H

#include <QGraphicsTextItem>
#include <QFont>

class LoseWinText : public QGraphicsTextItem
{
public:
    LoseWinText(QGraphicsItem *parent = nullptr);
    void ShowLose(void);
    void ShowWin(void);

};

#endif // LOSEWINTEXT_H
