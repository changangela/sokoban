#ifndef SCORE_H_
#define SCORE_H_

#include <vector>
#include <string>

class Score {
	int m_moves;
	std::string m_name;
	int m_level;
public:
	Score();
	Score(int move, std::string name, int level);
	virtual ~Score();
	void setMoves(int move);
	int getMoves();
	void setName(std::string name);
	std::string getName();
	void setLevel(int level);
	int getLevel();
};

#endif /* SCORE_H_ */
