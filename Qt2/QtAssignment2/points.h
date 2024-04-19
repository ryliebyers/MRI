#ifndef POINTS_H
#define POINTS_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class Points : public QObject
{
    Q_OBJECT
public:
    explicit Points(QObject *parent = nullptr);
    int m_points;
    QLabel *m_label;
    bool isWon() const;
    void addPoints(int amount);
    void minusPoints(int amount);
    int getPoints() const;
    void updatePointsLabel();
signals:
    void pointsChanged(int points);
};

#endif // POINTS_H
