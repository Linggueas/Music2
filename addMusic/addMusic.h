#pragma once

#include <QMainWindow>
#include "ui_addMusic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class addMusicClass; };
QT_END_NAMESPACE

class addMusic : public QMainWindow
{
	Q_OBJECT

public:
	addMusic(QWidget *parent = nullptr);
	~addMusic();
signals :
	void givesign(QString& name, QString& file);
public slots:

private:
	Ui::addMusicClass *ui;
};
