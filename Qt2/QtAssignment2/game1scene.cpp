//Author: Mina Akbari
//Assignment: Qt2
//Course: CS6015
//Date: April 15, 2024

#include "game1scene.h"
#include "cloud.h"
#include <QBrush>
#include <QImage>
#include <QKeyEvent>
#include "sound.h"
#include "droplet.h"
Game1Scene::Game1Scene() {
    // Set background image
    QImage backgroundImage(":/images/background.jpg");
    if (backgroundImage.isNull()) {
        qDebug() << "Error loading background image: " << backgroundImage;
    } else {
        // Set background image
        setBackgroundBrush(QBrush(QImage(":/images/background.jpg").scaledToHeight(512).scaledToWidth(910)));
    }

    // Set scene rectangle
    setSceneRect(0, 0, 910, 512);

    // Create and add bucket
    bucket = new Bucket();
    bucket->setPixmap((QPixmap(":/images/bucket.png")).scaled(130, 130));

    addItem(bucket);
    bucket->setPos(400, 390);
    bucket->setFlag(QGraphicsItem::ItemIsFocusable);
    bucket->setFocus();

    // Create timer for droplets
    timerDrop = new QTimer(this);
    connect(timerDrop, &QTimer::timeout, this, &Game1Scene::addDroplet);
    timerDrop->start(600);

    // Create and add clouds
    Cloud *cloud1 = new Cloud();
    Cloud *cloud2 = new Cloud();
    Cloud *cloud3 = new Cloud();
    Cloud *cloud4 = new Cloud();
    Cloud *cloud5 = new Cloud();

    addItem(cloud1);
    addItem(cloud2);
    addItem(cloud3);
    addItem(cloud4);
    addItem(cloud5);

    // Set positions for the clouds
    cloud1->setPos(50, -10);
    cloud2->setPos(200, 10);
    cloud3->setPos(350, -5);
    cloud4->setPos(550, 10);
    cloud5->setPos(700, 0);

    // connect(m_droplet, &Points::addPoints, &m_points, &Points::addPoints);
    // connect(m_droplet, &Points::minusPoints, &m_points, &Points::minusPoints);

    // // Create points rectangle
    pointsRect = addRect(10, 10, 100, 50, QPen(Qt::black), QBrush(Qt::white)); // Create a white rectangle
    pointsRect->setFlag(QGraphicsItem::ItemIsSelectable, false);
    pointsRect->setFlag(QGraphicsItem::ItemIsFocusable, false);
    pointsRect->setFlag(QGraphicsItem::ItemIsMovable, false);
    updatePointsDisplay();

}

Game1Scene::~Game1Scene() {
    delete bucket;
}




void Game1Scene::updatePointsDisplay() {
    // Update text in points rectangle
    QString pointsText = QString("Points: %1").arg(pointsValue);
    QGraphicsTextItem *pointsTextItem = new QGraphicsTextItem(pointsText, pointsRect);
    QPointF textPos = pointsRect->boundingRect().center() - pointsTextItem->boundingRect().center();
    pointsTextItem->setPos(textPos);
}




void Game1Scene::addDroplet() {
    // Create droplet
    Droplet *droplet = new Droplet();
    droplet->setPixmap((QPixmap(":/images/water.gif")).scaled(30, 30));
    addItem(droplet);
    droplet->setPos(rand() % 800, 0); // Random position under clouds

    // Connect signal for deletion
    connect(droplet, &Droplet::outOfScene, [=]() {
        removeItem(droplet);
        delete droplet;
    });

}






