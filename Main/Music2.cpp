#include "Music2.h"
#include"../addMusic/addMusic.h"

Music2::Music2(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Music2Class())
{
    f = 0;
    ui->setupUi(this);
    m_play = new QMediaPlayer(this);
    m_audio = new QAudioOutput(this);
    m_play->setAudioOutput(m_audio);
    connect(ui->play_button, &QPushButton::clicked, this, &Music2::play_button_clicked);
    connect(ui->add_button, &QPushButton::clicked, this, &Music2::add_button_clicked);
    connect(ui->next_button, &QPushButton::clicked, this, &Music2::next_button_clicked);
    connect(ui->last_button, &QPushButton::clicked, this, &Music2::last_button_clicked);
    connect(m_play, &QMediaPlayer::durationChanged, this, &Music2::updateDuration);
    connect(m_play, &QMediaPlayer::positionChanged, this, &Music2::updatePosition);
    connect(ui->horizontalSlider, &QSlider::sliderMoved, m_play, &QMediaPlayer::setPosition);
    connect(ui->listWidget, &QListWidget::itemClicked, this, &Music2::onItemClicked);
    currentfile = "";
    currentname = "";
    inter = 0;
    haveMusic = false;
}

Music2::~Music2()
{
    delete ui;
}


void Music2::add_button_clicked()
{
    addMusic *a = new addMusic(this);
    a->show();
    connect(a, &addMusic::givesign, this, &Music2::give);
}
//last
void Music2::last_button_clicked()
{
    if (inter == 0) {
        return;
    }
    inter--;
    m_play->setSource(QUrl::fromLocalFile(music_list[inter]));
    m_play->play();
    f = 1;
    ui->play_button->setIcon(QIcon(":/new/prefix1/stop.png"));
    ui->label->setText(ui->listWidget->item(inter)->text());
    ui->listWidget->setCurrentRow(inter);
}
//next
void Music2::next_button_clicked()
{
    if (music_list.size()-1 == inter||music_list.size()==0) {
        return;
    }
    inter++;
    m_play->setSource(QUrl::fromLocalFile(music_list[inter]));
    m_play->play();
    f = 1;
    ui->play_button->setIcon(QIcon(":/new/prefix1/stop.png"));
    ui->label->setText(ui->listWidget->item(inter)->text());
    ui->listWidget->setCurrentRow(inter);
}


void Music2::give(QString& name, QString& file)
{
    currentname = name;
    currentfile = file;
    ui->listWidget->addItem(currentname);
    music_list.push_back(currentfile);
}


void Music2::updateDuration(qint64 duration)
{
     ui->horizontalSlider->setRange(0, duration);  // 设置进度条范围
    // 可选：显示总时长（格式化为分:秒）
     int totalSeconds = duration / 1000;
     int minutes = totalSeconds / 60;
     int seconds = totalSeconds % 60;
     ui->label_2->setText(
         QString("%1:%2")
         .arg(minutes, 2, 10, QLatin1Char('0'))
         .arg(seconds, 2, 10, QLatin1Char('0'))
     );
}
void Music2::updatePosition(qint64 position)
{
    ui->horizontalSlider->setValue(position);
    int currentSeconds = position / 1000;
    int minutes = currentSeconds / 60;
    int seconds = currentSeconds % 60;
    ui->label_2->setText(
        QString("%1:%2")
        .arg(minutes, 2, 10, QLatin1Char('0'))
        .arg(seconds, 2, 10, QLatin1Char('0'))
    );
}

void Music2::setPosition(int position)
{
    m_play->setPosition(position);
}
void Music2::onItemClicked(QListWidgetItem* item)
{
    int row = ui->listWidget->row(item);
    inter = row;
    m_play->setSource(QUrl::fromLocalFile(music_list[inter]));
    ui->label->setText(ui->listWidget->item(inter)->text());
    m_play->play();
    ui->play_button->setIcon(QIcon(":/new/prefix1/stop.png"));
    f = 1;
}
void Music2::play_button_clicked() {
    if (haveMusic) {
        goto A;
    }
    if (!music_list.isEmpty()) {
        m_play->setSource(QUrl::fromLocalFile(music_list[inter]));
        haveMusic = true;
        ui->label->setText(ui->listWidget->item(inter)->text());
        ui->listWidget->setCurrentRow(inter);
    }
    else {
        return;
    }
A:
    if (f == 0) {
        f = 1;
        ui->play_button->setIcon(QIcon(":/new/prefix1/stop.png"));
        m_play->play();
        
    }
    else {
        f = 0;
        ui->play_button->setIcon(QIcon(":/new/prefix1/play.png"));
        m_play->pause();
    }
}
