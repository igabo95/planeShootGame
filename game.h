#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"
#include <QMediaPlayer>
#include <QAudioOutput>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

private:
    QMediaPlayer * backgroundMusic;
    QAudioOutput * backgroundOutput;
};


#endif // GAME_H
