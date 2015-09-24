#include "gamePlay.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

#include <QDebug>
#include <QMessageBox>

GamePlay::GamePlay(QWidget *parent) :
	QDialog(parent),
	gpd(new GamePlay)
{
	gpd->setWindowTitle("Rock-Paper-Scissors");
	gpd->setVisible(true);

	connect(gpd->backButton,    SIGNAL(clicked()), this, SLOT(goBack()));
	connect(gpd->confirmButton, SIGNAL(clicked()), this, SLOT(showResult()));
}

GamePlay::~GamePlay()
{
	delete gpd;
}

/* Private slots */
void GamePlay::goBack()
{
	gpd->setVisible(false);
}

void GamePlay::showResult()
{
	Choices user	 = gpd->getUserChoice();
	Choices computer = gpd->generateComputerChoice();
	bool win	 = gpd->gameLogic(user, computer);

	QMessageBox *outcome = new QMessageBox(this);
	if (win) {
		outcome->setWindowTitle("Congratulations");
		outcome->setText("You Win !");
	} else {
		outcome->setWindowTitle("Commisserations");
		outcome->setText("You Lose. Better luck next time.");
	}
}

/* Public methods */
Choices GamePlay::getUserChoice()
{
	if (rockButton->isChecked()) {
		userChoice = rock;
	} else if (paperButton->isChecked()) {
		userChoice = paper;
	} else if (scissorButton->isChecked()) {
		userChoice = scissors;
	}

	return userChoice;
}

Choices GamePlay::generateComputerChoice()
{
	int computerChoiceIndicator;

	srand((unsigned)time(NULL));
	computerChoiceIndicator = rand() % 3;

	switch (computerChoiceIndicator) {
		case 0 : {
			computerChoice = rock;
			break;
		}
		case 1 : {
			computerChoice = paper;
			break;
		}
		case 2 : {
			computerChoice = scissors;
			break;
		}
		default : {
			qDebug() << "\nSomething went wrong. Terminating\n";
		}
	}

	return computerChoice;
}

//Returns true if the user wins
bool GamePlay::gameLogic(Choices u, Choices c)
{
	if (u == c) {
		// Draw
		qDebug() << "\nIt's a tie !";
	} else if (u == rock) {
		if (c == paper) {
			qDebug() << "\nThe computer chose paper. You lose.";
			return false;
		} else if (c == scissors) {
			qDebug() << "\nThe computer chose scissors. You win.";
			return true;
		}
	} else if (u == paper) {
		if (c == rock) {
			qDebug() << "\nThe computer chose rock. You win.";
			return true;
		} else if (c == scissors) {
			qDebug() << "\nThe computer chose scissors. You lose";
			return false;
		}
	} else if (u == scissors) {
		if (c == rock) {
			qDebug() << "\nThe computer chose rock. You lose";
			return false;
		} else if (c == paper) {
			qDebug() << "\nThe computer chose paper. You win";
			return true;
		}
	}
	return false;
}
