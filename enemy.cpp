
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "game.h"

extern Game * game;


Enemy::Enemy(QGraphicsItem * parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // set position
    int random = rand() % 700; //((int)scene()->width() - m_width);
    setPos(random, 0);

    // create enemy item to put in the scene
    //setRect(0,0,70,20);
    setPixmap(QPixmap(":/images/images/bf109_png.png"));

    // connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(20);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(), y()+5);

    // Delete ouside enemies
    if (pos().y() > scene()->height())
    {
        // Decrease health points
        game->health->decrease();

        // Remove and Delete Enemy obj
        scene()->removeItem(this);
        delete this;
    }
}
