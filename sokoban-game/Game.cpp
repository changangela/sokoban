#include "Game.h"

Game::Game() {
	m_scoreList = new ScoreList();
	m_mainMenu = new MainMenu(m_scoreList);
	m_board = new Board(m_mainMenu->getLevelSelection());
	m_action = 'w';
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::initialize() {
	// main menu is displayed and game starts
	m_mainMenu->display();
	// initializes the new board to a user selected level
	Box::resetNumBox(); // reset static variables
	Box::setNumInHole(0); // reset static variables
	m_board = new Board(m_mainMenu->getLevelSelection());
	cout << "-----------------------------\n";
	cout << "            LEVEL " << m_board->getLevel() + 1 << "          \n";
	cout << "-----------------------------\n";
	m_board->printBoard();
	playerAction();
}
void Game::playerAction() {
	// read user input
	cout << "Move [a/w/d/s/?]: ";
	cin >> m_action;

	processAction(); // processes user action

	cout << endl;
	m_board->printBoard(); // prints out current board

	// checks if the player has won
	if (m_board->isWin()) {
		cout << "Congratulations! You have beat level "
				<< m_board->getLevel() + 1 << " in " << m_board->getMoves()
				<< " moves! " << endl;

		// adds the player winning information to high score
		string tempName;
		cout << "Enter your name for scoreboard: ";
		cin >> tempName;
		m_scoreList->addScore(m_board->getMoves(), tempName,
				m_board->getLevel());

		cout << "Press Enter key to continue to level "
				<< m_board->getLevel() + 1 + 1 << "..." << endl;
		MainMenu::pressEnterToContinue();
		if (m_board->getLevel() + 1 == m_board->getNumLevels()) {
			// there are no more levels
			cout << "This level is to be continued..." << endl;
			cout << "Press Enter key to continue to the Main Menu..." << endl;
			MainMenu::pressEnterToContinue();
			m_mainMenu = new MainMenu(m_scoreList);
		} else {
			// instantialize a new board with the next level
			newBoard(m_board->getLevel() + 1);
		}
	} else {
		// recursive function that allows for reiteration of the playerAction() method given that the conditions have been met
		playerAction();
	}
}

void Game::processAction() {
// process user input [w/d/s/a]
	switch (m_action) {
	case 'w':
		m_board->move(Offset(-1, 0));
		break;
	case 'a':
		m_board->move(Offset(0, -1));
		break;
	case 's':
		m_board->move(Offset(+1, 0));
		break;
	case 'd':
		m_board->move(Offset(0, +1));
		break;
	case 'r':
		newBoard(m_board->getLevel());
		break;
	case 'm':
		initialize();
	case '?':
		help();
		break;
	default:
		// invalid directional input
		// cout << "INVALID DIRECTION\n\n";
		break;
	}
}
void Game::newBoard(int level) {
// initializes a new Board
	Box::resetNumBox(); // reset static variables
	Box::setNumInHole(0); // reset static variables
	m_board = new Board(level);
	m_board->printBoard();
	playerAction();
}

void Game::help() {
	// help menu displays keyboard input legend
	cout << "-----------------------------\n";
	cout << "             HELP            \n";
	cout << "-----------------------------\n";
	cout << "@ - player\t$ - box" << endl;
	cout << ". - hole\t# - wall" << endl;
	cout << "+ - player in hole" << endl;
	cout << "* - box in hole" << endl;
	cout << endl;
	cout << "'w' = up\t's' = down" << endl;
	cout << "'a' = left\t'd' = right" << endl;
	cout << "'r' = restart\t'm' = root menu" << endl;
	cout << " - all commands require the Enter key to be pressed...";
	MainMenu::pressEnterToContinue();
}
