#include "gamehistorymanager.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

GameHistoryManager::GameHistoryManager(QObject *parent) : QObject(parent) {}

void GameHistoryManager::saveGameData(const GameData& data) {
    QFile file("game_history.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << data.date.toString(Qt::ISODate) << " " << data.username << " " << data.score << "\n";
        file.close();
    } else {
        qDebug() << "Failed to open file for writing.";
    }
}

void GameHistoryManager::saveGameScore(const QString& username, int score) {
    GameData data;
    data.date = QDateTime::currentDateTime();
    data.username = username;
    data.score = score;
    saveGameData(data);
}
