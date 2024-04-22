#include "gamehistorymanager.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include "userinfo.h"
#include "globals.h"
GameHistoryManager::GameHistoryManager(QObject *parent) : QObject(parent) {}


void GameHistoryManager::saveGameData(const GameData& data) {
    QFile file( data.username  + ".txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);

        if(totalPoints ==150 || &QApplication::quit){
        out << data.date.toString(Qt::ISODate) << " "<< totalPoints << "\n";
        }
        file.close();
    } else {
        qDebug() << "Failed to open file for writing.";
    }
}


void GameHistoryManager::saveGameScore(const QString& username,const GameData& data ) {
    // Create directory if it doesn't exist
    QDir().mkpath("user_scores");

    // Open the file for appending
    QFile file( data.username  + ".txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        // Write the score and current date to the file
        if(totalPoints ==150 || &QApplication::quit){

        out << QDateTime::currentDateTime().toString(Qt::ISODate) << " " << totalPoints << "\n";
        }
        file.close();
    } else {
        qDebug() << "Failed to open file for writing.";
    }
}

int GameHistoryManager::getUserBestScore(const GameData& data) {

    // Open the user's score file for reading
    QFile file( data.username  + ".txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        int bestScore = 0;
        // Read each line and extract the score
        while (!in.atEnd()) {
            QString line = in.readLine();
            int score = line.split(" ").last().toInt();
            // Update bestScore if the current score is higher
            if (score > bestScore) {
                bestScore = score;
            }
        }
        file.close();
        return bestScore;
    } else {
        qDebug() << "Failed to open file for reading.";
        return 0;
    }
}
