#include "gamePlay.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

GamePlay::GamePlay(QWidget *parent) :
	QDialog(parent),
	backButton(new QPushButton("Back"))  , confirmButton(new QPushButton("Confirm")),
	rockButton(new QRadioButton("Rock")) , paperButton(new QRadioButton("Paper")), scissorButton(new QRadioButton("Scissors"))
{
	setWindowTitle("Rock-Paper-Scissors");

	gameWindow = new QWidget;
	QVBoxLayout *mainLayout = new QVBoxLayout;
	QVBoxLayout *vLayout    = new QVBoxLayout;
	QHBoxLayout *hLayout    = new QHBoxLayout;

	hLayout->addWidget(backButton);
	hLayout->addWidget(confirmButton);
	vLayout->addWidget(rockButton);
	vLayout->addWidget(paperButton);
	vLayout->addWidget(scissorButton);

	mainLayout->addLayout(vLayout);
	mainLayout->addLayout(hLayout);
	gameWindow->setLayout(mainLayout);
	gameWindow->show();

	connect(backButton,    SIGNAL(clicked()), this, SLOT(goBack()));
	connect(confirmButton, SIGNAL(clicked()), this, SLOT(showResult()));
	connect(rockButton,    SIGNAL(toggled(bool)), this, SLOT(selectionMade()));
	connect(paperButton,   SIGNAL(toggled(bool)), this, SLOT(selectionMade()));
	connect(scissorButton, SIGNAL(toggled(bool)), this, SLOT(selectionMade()));
}

GamePlay::~GamePlay()
{
	delete gameWindow;
}

/* Private slots */
void GamePlay::goBack()
{
	gameWindow->close();
}

void GamePlay::showResult()
{
	Choices user	 = getUserChoice();
	Choices computer = generateComputerChoice();
	bool win	 = gameLogic(user, computer);

	outcomeWindow = new QMessageBox();
	gameWindow->close();
	if (win) {
		outcomeWindow->setWindowTitle("Congratulations");
		outcomeWindow->setText("You Win !");
	} else {
		outcomeWindow->setWindowTitle("Commisserations");
		outcomeWindow->setText("You Lose. Better luck next time.");
	}
	outcomeWindow->show();
}

void GamePlay::selectionMade()
{
	getUserChoice();
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
