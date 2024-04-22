#ifndef GAMEHISTORYMANAGER_H
#define GAMEHISTORYMANAGER_H

#include <QObject>
#include <QDateTime>

struct GameData {
    QDateTime date;
    QString username;
    int score;
};

class GameHistoryManager : public QObject
{
    Q_OBJECT

public:
    explicit GameHistoryManager(QObject *parent = nullptr);

    void saveGameScore(const QString& username, int score);

private:
    void saveGameData(const GameData& data);
};

#endif // GAMEHISTORYMANAGER_H
