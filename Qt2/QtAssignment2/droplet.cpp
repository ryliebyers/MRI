//Author: Mina Akbari
//Assignment: Qt2
//Course: CS6015
//Date: April 15, 2024

#include "droplet.h"
#include <QTimer>
#include <QRandomGenerator>
#include <QGraphicsScene>
#include "bucket.h"
#include "sound.h"
Droplet::Droplet() {
    // Set up timer for movement
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Droplet::moveDroplet);
    timer->start(50);//speed
}

Droplet::~Droplet() {
    delete timer;
}

//method that moves droplets
void Droplet::moveDroplet() {
    Sound *sound = new Sound;

    //if pos is within screen then move droplet
    if (scene() && pos().y() < scene()->height()) {
        setPos(x(), y() + 10);
        //checkes for collision
        QList<QGraphicsItem*> colliding_items = collidingItems();
        //iterate through all collisions
        for (int i = 0; i < colliding_items.size(); ++i) {
            //if same type where bucket is then remove droplet and returns
            if (typeid(*(colliding_items[i])) == typeid(Bucket)) {
                scene()->removeItem(this);
                delete this;
                sound->AddSplash();

                return;
            }
        }
    } else {
        //Out of window
        scene()->removeItem(this);
        sound->AddBeep();

        delete this;
    }
    delete sound;

}
