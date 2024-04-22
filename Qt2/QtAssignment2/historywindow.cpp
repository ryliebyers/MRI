// historywindow.cpp
#include "signupui.h"
#include "userinfo.h"
#include "historywindow.h"
#include "gamehistorymanager.h"
#include <QMessageBox>
#include "globals.h"
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

void HistoryWindow::populateScores() {
    QMultiMap<int, QString> scores; // Using QMultiMap to store multiple values for the same key
    QFile file("user_score.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(" ");
            if (parts.length() == 2) {
                int score = parts[1].toInt();
                QString date = parts[0];
                scores.insert(score, date); // Using insert to allow multiple values for the same key
            }
        }
        file.close();
    } else {
        qDebug() << "Failed to open file for reading user score.";
    }

    // Displaying scores in descending order
    QList<int> scoreKeys = scores.uniqueKeys(); // Getting unique keys
    std::sort(scoreKeys.begin(), scoreKeys.end(), std::greater<int>()); // Sorting keys in descending order
    if (!scoreKeys.isEmpty()) {
        int bestScore = scoreKeys.first(); // Highest score
        QString bestScoreDate = scores.value(bestScore); // Date of highest score

        if(totalPoints <= 150 && isWon){
        userScoreLabel->setText("Your Score: " + QString::number(totalPoints));
        }
        bestScoreLabel->setText("Best Score: " + QString::number(bestScore) + " achieved on " + bestScoreDate);

        // Display all scores in descending order
        QString allScores;
        foreach (int score, scoreKeys) {
            QList<QString> dates = scores.values(score); // Getting all dates for the current score
            foreach (const QString &date, dates) {
                allScores += "Score: " + QString::number(score) + " Date: " + date + "\n";
            }
        }
        QMessageBox::information(this, "Game History", "Your Scores:\n" + allScores);
    } else {
        userScoreLabel->setText("Your Score: 0");
        bestScoreLabel->setText("Best Score: 0");
        QMessageBox::information(this, "Game History", "No scores found.");
    }
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

//Do a file per username
// score Score date
//save score when quit game
//have it write out.
//when displaying have it readin the file and find high score
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
