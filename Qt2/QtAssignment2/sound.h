#ifndef SOUND_H
#define SOUND_H

#include <QObject>
#include <QAudio>
#include <QMediaPlayer>
class Sound : public QObject
{
    Q_OBJECT
public:
    explicit Sound(QObject *parent = nullptr);
    void AddSplash();
    void AddBeep();
signals:
};

#endif // SOUND_H
