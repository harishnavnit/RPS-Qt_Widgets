#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamePlay.h"

#include <QMainWindow>

namespace Ui {
	class MainWindow;
	class GamePlay;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots :
	bool playButtonClicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
