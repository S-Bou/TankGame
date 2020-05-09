#ifndef EVADED_H
#define EVADED_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QFont>

class Evaded : public QGraphicsTextItem
{
public:
    Evaded(QGraphicsItem *parent=nullptr);
    void DecreaseEvaded(void);
    void ResetLives(void);
    void SoundLose(void);
    int getEvaded() const;

private:
    QMediaPlayer *soundLose;
    int evaded;
};

#endif // EVADED_H
