//Author: Mina Akbari
//Assignment: Qt2
//Course: CS6015
//Date: April 15, 2024

#ifndef GAME1SCENE_H
#define GAME1SCENE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "bucket.h"
#include <QGraphicsItem>
#include "droplet.h"

class Game1Scene : public QGraphicsScene {
    Q_OBJECT
public:
    Game1Scene();
    ~Game1Scene();
private:
    Bucket *bucket;
    QTimer *timerDrop;
public slots:
    void addDroplet();
};
#endif // GAME1SCENE_H

