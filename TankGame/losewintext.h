#ifndef LOSEWINTEXT_H
#define LOSEWINTEXT_H

#include <QGraphicsTextItem>
#include <QFont>

class LoseWinText : public QGraphicsTextItem
{
private:

public:
    LoseWinText(QGraphicsItem *parent = nullptr);
    void ShowLose(void);
    void ShowWin(void);

signals:

};

#endif // LOSEWINTEXT_H
