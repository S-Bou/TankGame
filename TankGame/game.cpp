#include "game.h"

extern WindowStart *s;

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    timer = new QTimer();

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

    //Play background music
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/MusicBackg.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    //Play background music as loop
    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
}

Game::~Game()
{
    delete timer;
    delete scene;
    delete score;
    delete player;
    delete evaded;
}

void Game::StartGame(void)
{
    //Create enemies when user push start
    player->spawnEnemy();

    //timer = new QTimer();
    connect(timer, SIGNAL(timeout()), player, SLOT(spawnEnemy()));
    timer->start(2000);
}

void Game::ResetGameLose()
{
    //If evade 4 or more enemies show init window
    disconnect(timer, SIGNAL(timeout()), player, SLOT(spawnEnemy()));
    losewin->ShowLose();
    scene->addItem(losewin);
    s->show();
}

void Game::ResetGameWin()
{
    //If destroy 10 or more enemies show init window
    disconnect(timer, SIGNAL(timeout()), player, SLOT(spawnEnemy()));
    losewin->ShowWin();
    scene->addItem(losewin);
    s->show();

}

void Game::ResetLevels()
{
    evaded->ResetLives();
    score->ResetScore();
    scene->removeItem(losewin);
    //Shot *shot = new Shot(nullptr);
    //shot->StopShot();
}


