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
#include "mainwindow.h"
#include "windowstart.h"
#include "losewintext.h"

class Game : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    LoseWinText *lose;
    QTimer *timer;
    Player *player;

public:
    Game(QWidget *parent=nullptr);
    ~Game();
    void StartGame(void);
    void ResetGame(void);
    void ResetLevels(void);
    Score *score;
    Evaded *evaded;

};

#endif // GAME_H
