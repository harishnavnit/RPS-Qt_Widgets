#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "mainwindow.h"
#include "ui_gamePlay.h"

#include <QDialog>

enum Choices {
	rock,
	paper,
	scissors
};

class GamePlay : public QDialog
{
	Q_OBJECT

public:
	explicit GamePlay(QWidget *parent = 0);
	~GamePlay();

	void generateResult();
	Choices getUserChoice();
	Choices generateComputerChoice();
	bool gameLogic(Choices, Choices);

private slots:
	void goBack();
	void showResult();

private:
	QRadioButton *rockButton, *paperButton, *scissorButton;
	QPushButton *confirmButton, *backButton;
	GamePlay *gpd;
	Choices userChoice, computerChoice;
};
#endif // GAMEPLAY_H
