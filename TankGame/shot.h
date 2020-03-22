#ifndef SHOT_H
#define SHOT_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "player.h"
#include <QObject>
#include <QTimer>
#include <QDebug>

class Shot: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Player *jugador;
    int direccion;

public:
    Shot(Player*);

public slots:
    void moveShotPlayer();

};

#endif // SHOT_H
