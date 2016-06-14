#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <iostream>

#include "Player.h"
#include "Box.h"
#include "Wall.h"
#include "Hole.h"
#include "Space.h"

using namespace std;

class Board {
private:
	int m_level;
	Player* m_player;
	vector<Box*> m_boxes;

	vector<string> m_stage;
	void addStage();
	vector<vector<Unit*> > parseStage(int level);

	vector<vector<Unit*> > m_board;

public:
	Board();
	Board(int level);
	void printBoard();
	bool isWin();
	void move(Offset offset);
	void setLevel(int level);
	int getLevel();
	int getNumLevels();
	int getMoves();
	virtual ~Board();
};

#endif /* BOARD_H_ */
