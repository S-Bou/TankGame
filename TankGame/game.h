#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget *parent=nullptr);

    QGraphicsScene *scene;
    Player *player;
};

#endif // GAME_H
