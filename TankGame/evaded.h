#ifndef EVADED_H
#define EVADED_H

#include <QGraphicsTextItem>
#include <QFont>

class Evaded : public QGraphicsTextItem
{
public:
    Evaded(QGraphicsItem *parent=nullptr);
    void DecreaseEvaded(void);
    void ResetLives(void);

private:
    int evaded;
};

#endif // EVADED_H
