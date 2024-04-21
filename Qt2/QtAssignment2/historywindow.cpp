// historywindow.cpp

#include "historywindow.h"

HistoryWindow::HistoryWindow(QWidget *parent) : QWidget(parent)
{
    titleLabel = new QLabel("Game History");
    userScoreLabel = new QLabel("Your Score: ");
    bestScoreLabel = new QLabel("Best Score: ");
    layout = new QVBoxLayout(this);

    layout->addWidget(titleLabel);
    layout->addWidget(userScoreLabel);
    layout->addWidget(bestScoreLabel);

    populateScores();

    setLayout(layout);
}

void HistoryWindow::populateScores()
{
    int userScore = getUserScore();
    int bestScore = getBestScore();

    userScoreLabel->setText("Your Score: " + QString::number(userScore));
    bestScoreLabel->setText("Best Score: " + QString::number(bestScore));
}

int HistoryWindow::getUserScore()
{
    // Retrieve the user's score from a file or database
    QFile file("user_score.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading user score.";
        return 0;
    }

    QTextStream in(&file);
    int score = 0;
    if (!in.atEnd()) {
        score = in.readLine().toInt();
    }

    file.close();
    return score;
}

int HistoryWindow::getBestScore()
{
    // Retrieve the global best score from a file or database
    QFile file("best_score.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading best score.";
        return 0;
    }

    QTextStream in(&file);
    int score = 0;
    if (!in.atEnd()) {
        score = in.readLine().toInt();
    }

    file.close();
    return score;
}
