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
#include "points.h"

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
 //   Points *points = new Points;
   // Points point;
  //Sound sound;
    //if pos is within screen then move droplet
    if (scene() && pos().y() < scene()->height()) {
        setPos(x(), y() + 10);
        //checkes for collision
        QList<QGraphicsItem*> colliding_items = collidingItems();
        //iterate through all collisions
        for (int i = 0; i < colliding_items.size(); ++i) {
            //if same type where bucket is then remove droplet and returns
            if (typeid(*(colliding_items[i])) == typeid(Bucket)) {
                sound->AddSplash();
                m_points.addPoints(5);
                // Call the isWon method
                if (m_points.isWon()) {
                    qDebug() << "You won!";
                } else {
                    qDebug() << "You haven't won yet.";
                }

                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    } else {
        //Out of window
        sound->AddBeep();
        m_points.minusPoints(5);
        scene()->removeItem(this);
        delete this;
    }
     delete sound;
    // delete points;
}
