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

    int getUserBestScore(const GameData& data);
  void  saveGameScore(const QString& username,const GameData& data );
private:
    void saveGameData(const GameData& data);
};

#endif // GAMEHISTORYMANAGER_H
