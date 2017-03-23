#ifndef GAME_H_
#define GAME_H_
#include "Board.h"
#include "MainMenu.h"
class Game {
	Board* m_board;
	MainMenu* m_mainMenu;
	ScoreList* m_scoreList;
	char m_action;
	void playerAction();
	void processAction();
	void newBoard(int level);
	void help();
public:
	Game();
	virtual ~Game();
	void initialize();
};

#endif /* GAME_H_ */
