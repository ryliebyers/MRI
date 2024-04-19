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
#include "points.h"
#include "droplet.h"


class Game1Scene : public QGraphicsScene {
    Q_OBJECT
public:
    Game1Scene();
    ~Game1Scene();
private:
    Bucket *bucket;
    QTimer *timerDrop;
    QGraphicsRectItem *pointsRect;
    int pointsValue;
    Droplet *m_droplet;
    Points *m_points;
    QGraphicsTextItem *m_pointsLabel;
public slots:
    void addDroplet();
    void updatePointsDisplay();

};
#endif // GAME1SCENE_H

