#include "sound.h"
#include <QtMultimedia/QMediaPlayer>
#include <QMediaPlayer>
#include <QAudio>
#include <QSoundEffect>
#include <QAudioOutput>
Sound::Sound(QObject *parent)
    : QObject{parent}
{

}

void Sound::AddSplash() {
    QMediaPlayer *splash = new QMediaPlayer;
   QAudioOutput *audioOutput = new QAudioOutput;
    splash->setAudioOutput(audioOutput);


    //for volume bar???
  // Connect positionChanged signal of splash to a lambda function
   // connect(splash, &QMediaPlayer::positionChanged, [=](qint64 position){
   //     // Handle position changed here
   //     qDebug() << "Position changed to" << position;
   // });

    audioOutput->setVolume(50);
    splash->setSource(QUrl::fromLocalFile(":/sounds/Splash.wav"));

    splash->play();
}




void Sound::AddBeep() {
    QMediaPlayer *beep = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;

    beep->setSource(QUrl::fromLocalFile(":/sounds/Beep.mp3"));
    audioOutput->setVolume(50);

    beep->play();
}
