#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QObject>
#include <QDebug>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int direccion;
public:
    Enemy();

public slots:
    void moveEnemy();
};

#endif // ENEMY_H
