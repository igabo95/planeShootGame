#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>


class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT   // To handle signal and slots, a class must inherit from QObject, and must have Q_OBJECT macro
public:
    Bullet(QGraphicsItem * parent = 0);

public slots:
    void move();

private:
    int m_width = 10;
    int m_height = 50;
    QMediaPlayer * explosionSound;
    QAudioOutput * explosionAudioOutput;
};

#endif // BULLET_H
