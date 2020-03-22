#include "game.h"

Game::Game(QWidget *parent)
{
    (void) parent;
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

    //Create enemies
    player->spawnEnemy();

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), player, SLOT(spawnEnemy()));
    timer->start(2000);

    //show();
}


