#ifndef MAINMENU_H_
#define MAINMENU_H_
#include <iostream>
#include "stdlib.h"
#include "ScoreList.h"
using namespace std;
class MainMenu {
	int m_selection;
	int m_levelSelection;
	ScoreList* m_scoreList;
	void printInstructions();
	void levelSelect();
	void processLevelSelect();
public:
	MainMenu();
	MainMenu(ScoreList* scoreList);
	virtual ~MainMenu();
	void printMenu();
	void userSelection();
	void display();
	int getLevelSelection();
	static void pressEnterToContinue();
};

#endif /* MAINMENU_H_ */
