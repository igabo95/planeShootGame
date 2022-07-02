
#include <QGraphicsScene>
#include <QKeyEvent>
#include "player.h"
#include "enemy.h"
#include "bullet.h"



Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    // draw player
    setPixmap(QPixmap(":/images/images/p40_png.png"));

    // sounds
    bulletSound = new QMediaPlayer();
    bulletAudioOutput   = new QAudioOutput();
    bulletSound->setAudioOutput(bulletAudioOutput);
    bulletSound->setSource(QUrl("qrc:/sounds/sounds/short-laser.wav"));
    bulletAudioOutput->setVolume(30);
}

void Player::keyPressEvent(QKeyEvent *event)
{
//    qDebug() << "MyRect knows that u just pressed a key";

    if (event->key() == Qt::Key_Left && x() > 0)
    {
        setPos(x()-20, y());
    }
    else if (event->key() == Qt::Key_Right && x() < scene()->width() - this->width)
    {
        setPos(x()+20, y());
    }


    else if (event->key() == Qt::Key_Space)
    {
        // play bullet sound
        if (bulletSound->playbackState() == QMediaPlayer::PlayingState) bulletSound->setPosition(0);
        else if (bulletSound->playbackState() == QMediaPlayer::StoppedState) bulletSound->play();

        Bullet * bullet = new Bullet();
        bullet->setPos(x() + width/2 - 5, y());
        scene()->addItem(bullet);
    }
    else
    {

    }

}

void Player::spawn()
{
    // create new Enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
