// historywindow.h

#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class HistoryWindow : public QWidget
{
    Q_OBJECT
public:
    explicit HistoryWindow(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel *titleLabel;
    QLabel *userScoreLabel;
    QLabel *bestScoreLabel;
    QVBoxLayout *layout;

    void populateScores();
    int getUserScore();
    int getBestScore();
};

#endif // HISTORYWINDOW_H
