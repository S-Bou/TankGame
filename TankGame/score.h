#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent=nullptr);
    void IncreaseScore(void);
    void ResetScore(void);
    int getScore() const;

private:
    int score;
};

#endif // SCORE_H
