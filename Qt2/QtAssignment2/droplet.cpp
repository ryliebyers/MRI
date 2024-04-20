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
#include "globals.h"




Droplet::Droplet() {
    // Set up timer for movement
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Droplet::moveDroplet);
    timer->start(250);//speed
    speedUp();



}

Droplet::~Droplet() {
    delete timer;
}

//method that moves droplets
void Droplet::moveDroplet() {
    Sound *sound = new Sound;
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
                totalPoints+=5;
                DropsCaught += 1;

               // speedUp();


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
        totalPoints-=5;
        qDebug() << "Total points: " << totalPoints;
        scene()->removeItem(this);
        delete this;
    }
     delete sound;

}




void Droplet::speedUp() {
    qDebug() << "Total Collisions: " << DropsCaught;




    if (DropsCaught >= 5 && DropsCaught <= 9 ) {
        // x2
        if (timer->isActive()) {
            timer->stop(); // Stop the previous timer if active
        }
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Droplet::moveDroplet);
        timer->start(250/2); // Start a new timer with the updated speed
    } else if (DropsCaught >= 10 && DropsCaught <= 14) {
        // x4
        if (timer->isActive()) {
            timer->stop();
        }
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Droplet::moveDroplet);
        timer->start(250/4);
    } else if (DropsCaught >= 15 && DropsCaught <= 19 ) {
        // x8
        if (timer->isActive()) {
            timer->stop();
        }
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Droplet::moveDroplet);
        timer->start(250/8);
    } else if (DropsCaught >= 20) {
        // x16
        if (timer->isActive()) {
            timer->stop();
        }
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Droplet::moveDroplet);
        timer->start(250/16);
    }
}





