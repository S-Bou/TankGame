#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QKeyEvent>
#include "enemy.h"
#include <QPoint>
#include <QDebug>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int rotacion;
    Enemy *enemy;
    QMediaPlayer *bulletsound;

public:
    Player(QGraphicsItem *parent=nullptr);
    void keyPressEvent(QKeyEvent *event);
    void SetDireccionTank(int);

public slots:
    int getRotacion(void);
    void spawnEnemy(void);
    void DeleteEnemies(void);
};
#endif // PLAYER_H
