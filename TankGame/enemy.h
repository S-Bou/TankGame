#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QDateTime>

#include <QTimer>
#include <QObject>
#include <QDebug>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int RandomHandler(int, int);
    int direccion;
    QTimer *timer;

public:
    Enemy();
    ~Enemy();

public slots:
    void moveEnemy();
};

#endif // ENEMY_H
