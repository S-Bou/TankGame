#include "game.h"

extern WindowStart *s;

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    //Create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/grassTexture.jpg")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //Create player
    player = new Player();
    player->setPos(350,250);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    //Create score and evaded data
    score = new Score();
    scene->addItem(score);
    evaded = new Evaded();
    evaded->setPos(evaded->x(), evaded->y()+25);
    scene->addItem(evaded);

    //Create text for wen lose
    losewin = new LoseWinText();

    //Play background music, config it as list for play as loop
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/MusicBackg.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    playlist->setCurrentIndex(1);

    //Play background music as loop
    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    //Timer for start show enemies when is pressed button start
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), player, SLOT(spawnEnemy()));

    //Timer for check data constantly for determinade win or lose
    timerData = new QTimer();
    connect(timerData, SIGNAL(timeout()), this, SLOT(CheckScores()));
}

Game::~Game()
{
    delete timerData;
    delete timer;
    delete scene;
    delete score;
    delete player;
    delete evaded;
    delete music;
}

void Game::StartGame(void)
{
    //Create enemies when user push start
    player->spawnEnemy();
    timer->start(2000);
    timerData->start(500);
}

void Game::ResetGameLose()
{
    //If evade 4 or more enemies show init window
    evaded->SoundLose();
    timer->stop();
    losewin->ShowLose();
    scene->addItem(losewin);
    s->show();
}

void Game::ResetGameWin()
{
    //If destroy 10 or more enemies show init window
    score->SoundWin();
    timer->stop();
    losewin->ShowWin();
    scene->addItem(losewin);
    s->show();
}

void Game::ResetLevels()
{
    evaded->ResetLives();
    score->ResetScore();
    scene->removeItem(losewin);
}

void Game::CheckScores(void)
{
    if(score->getScore() >= 10)
    {
        ResetGameWin();
        timerData->stop();
    }

    if(evaded->getEvaded() <= 0)
    {
        ResetGameLose();
        timerData->stop();
    }
}

void Game::StateMusic(bool state)
{
    stateMusic = state;

    if(!state)
    {
        music->stop();
    }
    else
    {
        music->play();
    }
}


