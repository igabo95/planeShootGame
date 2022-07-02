#include <QApplication>
#include "game.h"
#include "button.h"

/*
Tutorial Topics:
-parents
-QGraphicsTextItem, setPlainText(), setFont(),setDefaultTextColor()
*/

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);



    game = new Game();
    game->show();
    game->displayMenu();

    return a.exec();
}
