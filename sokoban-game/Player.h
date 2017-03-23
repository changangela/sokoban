#ifndef PLAYER_H_
#define PLAYER_H_

#include "Moveable.h"
#include "Box.h"

class Player :public Moveable{
	bool m_inHole;
	int m_moves;
public:
	Player();
	Player(int row, int column);
	void pushBox(Box* box , Offset offset);
	void setInHole(bool inHole);
	bool getInHole();
	void setMoves(int moves);
	int getMoves();
	char toString();
	virtual ~Player();
};

#endif /* PLAYER_H_ */
