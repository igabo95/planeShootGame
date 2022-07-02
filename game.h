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
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    void displayMenu();

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

private:
    QMediaPlayer * backgroundMusic;
    QAudioOutput * backgroundOutput;

public slots:
    void start();
};


#endif // GAME_H
