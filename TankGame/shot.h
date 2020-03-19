#ifndef SHOT_H
#define SHOT_H

#include <QGraphicsRectItem>
#include <QObject>

class Shot: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Shot();
public slots:
    void move(void);

};

#endif // SHOT_H
