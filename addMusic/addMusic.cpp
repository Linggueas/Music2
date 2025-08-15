#include "addMusic.h"
#include"qfiledialog.h"
#include"qmessagebox.h"
addMusic::addMusic(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::addMusicClass())
{
	ui->setupUi(this);
	connect(ui->pushButton, &QPushButton::clicked,[this]() {
		QString name = ui->lineEdit->text();
		QString file = ui->lineEdit_2->text();
		if (name.isEmpty() || file.isEmpty()) {
			QMessageBox::warning(this, "错误", "歌曲名称或地址未填写");
			return;
		}
		emit givesign(name, file);
		this->close();
		});
	connect(ui->pushButton_2, &QPushButton::clicked, [this]() {
		QString fileName = QFileDialog::getOpenFileName(
			this, // 父窗口
			tr("打开文件"), // 对话框标题
			"D:/", // 初始目录（可选，默认是当前目录）
			tr("音频文件 (*.mp3 *.flac *.wav);;所有文件 (*)") // 过滤器
		);
		ui->lineEdit_2->setText(fileName);
		});
}

addMusic::~addMusic()
{
	delete ui;
}
