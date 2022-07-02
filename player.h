#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QAudioOutput>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent *event);
    int width = 100;
    int height = 100;

public slots:
    void spawn();

private:
    QMediaPlayer * bulletSound;
    QAudioOutput * bulletAudioOutput;
};

#endif // MYRECT_H
