/*
 * MainMenu.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: Angela
 */

#include "MainMenu.h"

MainMenu::MainMenu() {
	// TODO Auto-generated constructor stub
	m_selection = 0;
	m_levelSelection = 0;
	m_scoreList = new ScoreList;
}
MainMenu::MainMenu(ScoreList* scoreList) {
	// overloaded constructor
	m_selection = 0;
	m_levelSelection = 0;
	m_scoreList = scoreList;
}
MainMenu::~MainMenu() {
	// TODO Auto-generated destructor stub
}
void MainMenu::pressEnterToContinue() {
// utility function to allow user to press Enter to continue
	while (cin.get() != '\n') {
	}
	while (cin.get() != '\n') {
	}
}
void MainMenu::userSelection() {
	// recursive function that prompts user for input until input is valid
	cout << "Selection:                  ";
	cin >> m_selection;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Invalid selection." << endl;
		userSelection(); // recursive call
	} else {
		switch (m_selection) {
		case 1:
			// start new game continue as is
			break;
		case 2:
			// select a level
			levelSelect();
			break;
		case 3:
			// views scores
			m_scoreList->displayScore();
			pressEnterToContinue();
			display();
			break;
		case 4:
			// prints instructions to screen
			printInstructions();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "Invalid selection." << endl;
			userSelection(); // recursive call
		}
	}
}
void MainMenu::display() {
	// displays the main menu
	printMenu();
}
void MainMenu::printMenu() {
	// main menu is printed out
	cout << "-----------------------------\n";
	cout << "           SOKOBAN           \n";
	cout << "-----------------------------\n";
	cout << "New Game                    1\n";
	cout << "Level Select                2\n";
	cout << "Scores                      3\n";
	cout << "Instructions                4\n";
	cout << "Quit                        5\n";
	cout << "-----------------------------\n";
	userSelection();
}
int MainMenu::getLevelSelection() {
	return m_levelSelection;
}
void MainMenu::printInstructions() {
	// prints the instructions to screen
	cout << "-----------------------------\n";
	cout << "         INSTRUCTIONS        \n";
	cout << "-----------------------------\n";
	cout << endl;
	cout << "@ - player\t$ - box" << endl;
	cout << ". - hole\t# - wall" << endl;
	cout << "+ - player in hole" << endl;
	cout << "* - box in hole" << endl;
	cout << endl;
	cout
			<< "1. The game is played on a board of squares, where each square is a floor or a wall."
			<< endl;
	cout
			<< "2. Some floor squares contain boxes, and some floor squares are marked as Holes."
			<< endl;
	cout
			<< "3. The player is confined to the board, and may move horizontally or vertically onto empty squares."
			<< endl;
	cout << "4. The player may never move through walls or boxes." << endl;
	cout
			<< "5. The player can also move into a box, which pushes it into the square beyond."
			<< endl;
	cout
			<< "6. Boxes may not be pushed into other boxes or walls, and they cannot be pulled."
			<< endl;
	cout << "7. The puzzle is solved when all boxes are at storage locations."
			<< endl;
	cout
			<< "8. The player is controlled using the 'w','d','s', and 'a' characters followed by the Enter key."
			<< endl;
	cout << "9. The player can only move up, down, left, or right." << endl;
	cout
			<< "10. The objective of this game is to push all the Boxes into a Hole."
			<< endl << endl;
	cout << "Press Enter to go back to Main Menu..." << endl;
	pressEnterToContinue();
	display();
}
void MainMenu::levelSelect() {
	// prints the Level Selection to screen
	cout << "-----------------------------\n";
	cout << "         LEVEL SELECT        \n";
	cout << "-----------------------------\n";
	cout << "Level 1                     1\n";
	cout << "Level 2                     2\n";
	cout << "Level 3                     3\n";
	cout << "Level 4                     4\n";
	cout << "Level 5                     5\n";
	cout << "-----------------------------\n";
	processLevelSelect();
}
void MainMenu::processLevelSelect() {
	// processes the user selected level
	cout << "Selection:                  ";
	cin >> m_levelSelection;
	if (cin.fail()) {
		// if the input was not a valid integer
		cin.clear();
		cin.ignore();
		cout << "Invalid selection." << endl;
		processLevelSelect(); // recursive call
	} else {
		switch (m_levelSelection) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			// fall through switch case
			m_levelSelection--;
			break;
		default:
			cout << "Invalid selection." << endl;
			processLevelSelect(); // recursive call
		}
	}
}
