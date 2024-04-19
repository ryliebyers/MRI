//Author: Mina Akbari
//Assignment: Qt2
//Course: CS6015
//Date: April 15, 2024

#ifndef DROPLET_H
#define DROPLET_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
class Droplet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Droplet();
    ~Droplet();
    Droplet(const QPointF& cloudPosition);
private:
    QTimer *timer;
    qreal speed = 5;
private slots:
    void moveDroplet();
signals:
    void outOfScene();
};
#endif // DROPLET_H
