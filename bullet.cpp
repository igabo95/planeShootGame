
#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"
#include <QDebug>

extern Game * game;

Bullet::Bullet(QGraphicsItem * parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // create item to put in the scene
    //setRect(0,0,m_width,m_height);
    setPixmap(QPixmap(":/images/bullet_smallest.png"));

    // connect
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

    // sounds
    explosionSound = new QMediaPlayer();
    explosionAudioOutput = new QAudioOutput();
    explosionSound->setAudioOutput(explosionAudioOutput);
    explosionSound->setSource(QUrl("qrc:/sounds/distant-war-explosions.wav"));
    explosionAudioOutput->setVolume(20);
}

void Bullet::move()
{
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid( *(colliding_items[i]) ) == typeid(Enemy))
        {
            // increase the score
            game->score->increase();

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;

            // Explosion sound
            if (explosionSound->playbackState() == QMediaPlayer::PlayingState) explosionSound->setPosition(0);
            else if (explosionSound->playbackState() == QMediaPlayer::StoppedState) explosionSound->play();

            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    // move bullet up
    setPos(x(), y()-10);

    // Delete ouside bullets
    if (pos().y() < 0)
    {
        //scene()->removeItem(this);
        //delete this;
    }
}
