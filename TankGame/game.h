#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QObject>
#include "player.h"
#include "enemy.h"
#include "score.h"
#include <QTimer>
#include "evaded.h"

class Game : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    Player *player;

public:
    Game(QWidget *parent=nullptr);
    Score *score;
    Evaded *evaded;

};

#endif // GAME_H
