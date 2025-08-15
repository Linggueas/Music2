#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Music2.h"
#include"ui_addMusic.h"
#include"qmediaplayer.h"
#include"qaudiooutput.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Music2Class; };
QT_END_NAMESPACE

class Music2 : public QMainWindow
{
    Q_OBJECT

public:
    Music2(QWidget *parent = nullptr);
    ~Music2();
public slots:
    void play_button_clicked();
    void add_button_clicked();
    void last_button_clicked();
    void next_button_clicked();
    void give(QString& name, QString& file);
    void updateDuration(qint64 duration);
    void updatePosition(qint64 position);
    void setPosition(int position);
    void onItemClicked(QListWidgetItem* item);
private:
    Ui::Music2Class *ui;
    int f;
    QMediaPlayer *m_play;
    QAudioOutput *m_audio;
    QString currentname;
    QString currentfile;
    QList<QString>music_list;
    int inter;
    bool haveMusic;
};
