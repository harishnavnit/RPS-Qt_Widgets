#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDialog>
#include <QObject>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui->playButton, SIGNAL(clicked()), this, SLOT(playButtonClicked()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

/* Load the gameplay dialog
 * Hide the main window
 */
void MainWindow::playButtonClicked()
{
	new GamePlay();
}
