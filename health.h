#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsItem>


class Health : public QGraphicsTextItem
{
public:
    Health(QGraphicsItem *parent =0); // if not chose, parent becomes null pointer
    void decrease();
    int getHealth();

private:
    int m_health;

};

#endif // HEALTH_H
