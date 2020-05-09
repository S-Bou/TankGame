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
    QMediaPlaylist *playlist;
    QMediaPlayer *music, *soundLose;
    QTimer *timer;
    QTimer *timerData;
    Player *player;
    bool stateMusic;


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

public slots:
    void CheckScores(void);

};

#endif // GAME_H
