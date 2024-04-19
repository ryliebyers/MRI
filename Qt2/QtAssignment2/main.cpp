//Author: Mina Akbari
//Assignment: Qt2
//Course: CS6015
//Date: April 15, 2024

#include <QApplication>
#include <QGraphicsView>
#include "game1scene.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // Create the scene
    Game1Scene *scene1 = new Game1Scene();

    // Create view to visualize the scene
    QGraphicsView view(scene1);
    view.setFixedSize(910, 512);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();


    return a.exec();
}
