#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QObject>
#include "player.h"
#include "enemy.h"
#include "score.h"
#include "shot.h"
#include <QTimer>
#include "evaded.h"
#include "mainwindow.h"
#include "windowstart.h"
#include "losewintext.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

class Game : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    LoseWinText *losewin;
    QMediaPlayer *music;
    QTimer *timer;
    Player *player;

public:
    Game(QWidget *parent=nullptr);
    ~Game();
    void StartGame(void);
    void ResetGameLose(void);
    void ResetGameWin(void);
    void ResetLevels(void);
    void StateMusic(bool);
    Score *score;
    Evaded *evaded;

};

#endif // GAME_H
