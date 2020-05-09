#ifndef SHOT_H
#define SHOT_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "player.h"
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QList>
#include "enemy.h"
#include "game.h"

class Shot: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QMediaPlayer *soundHit;
    Player *jugador;
    QTimer *timer;
    int direccion;

public:
    void StopShot(void);
    Shot(Player*);
    ~Shot();

public slots:
    void moveShotPlayer(void);

};

#endif // SHOT_H
