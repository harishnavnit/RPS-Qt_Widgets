#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "mainwindow.h"
#include "ui_gamePlay.h"

#include <QDebug>
#include <QDialog>
#include <QMessageBox>

enum Choices {
	rock,
	paper,
	scissors
};

class GamePlay : public QDialog
{
	Q_OBJECT

public:
	explicit GamePlay(QWidget *parent=0);
	~GamePlay();

	Choices getUserChoice();
	Choices generateComputerChoice();
	bool gameLogic(Choices, Choices);

private slots:
	void goBack();
	void showResult();
	void selectionMade();

private:
	QWidget *gameWindow;
	QMessageBox *outcomeWindow;
	Choices userChoice, computerChoice;
	QPushButton *confirmButton, *backButton;
	QRadioButton *rockButton, *paperButton, *scissorButton;
};

#endif // GAMEPLAY_H
