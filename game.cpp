#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "button.h"
#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QBrush>


Game::Game(QWidget *parent){

    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    // Background
    setBackgroundBrush(QBrush(QImage(":/images/images/sky.jpg")));

    // add a view
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // show view
    show();
}

void Game::start()
{
    // Clear screen
    scene->clear();

    // Create Player to put in the scene
    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();         // make rect focusable
    player->setPos(width()/2, height()-120); // set player position
    scene->addItem(player);     // add item to the scene

    // spawn enemies
    QTimer * enemyTimer = new QTimer();
    QObject::connect(enemyTimer, SIGNAL(timeout()), player, SLOT(spawn()));
    enemyTimer->start(2000); // every 2 secs an enemy is created

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // play background music
    backgroundMusic  = new QMediaPlayer();
    backgroundOutput = new QAudioOutput();
    backgroundMusic->setAudioOutput(backgroundOutput);
    backgroundMusic->setSource(QUrl("qrc:/sounds/sounds/flying.mp3"));
    backgroundOutput->setVolume(30);
    backgroundMusic->play();
}

void Game::displayMenu()
{
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Plane Shooting Game !"));
    QFont titleFont("Times",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}



