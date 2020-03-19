#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>



class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int rotacion;

public:
    Player(QGraphicsItem *parent=nullptr);
    void keyPressEvent(QKeyEvent *event);

public slots:
    int getRotacion(void);

};
#endif // PLAYER_H