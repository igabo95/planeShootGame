#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT   // To handle signal and slots, a class must inherit from QObject, and must have Q_OBJECT macro
public:
    Enemy(QGraphicsItem * parent = 0);

public slots:
    void move();

private:
    int m_width = 10;
    int m_height = 50;
};

#endif // ENEMY_H
