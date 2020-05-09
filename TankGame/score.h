#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QFont>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent=nullptr);
    void IncreaseScore(void);
    void ResetScore(void);
    int getScore() const;
    void SoundWin(void);

private:
    QMediaPlayer *soundWin;
    int score;
};

#endif // SCORE_H
