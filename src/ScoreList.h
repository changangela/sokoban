/*
 * ScoreList.h
 *
 *  Created on: Jun 13, 2016
 *      Author: Angela
 */

#ifndef SCORELIST_H_
#define SCORELIST_H_

#include "Score.h"
#include <iostream>

using namespace std;
class ScoreList {
	int m_selectedLevel;
	std::vector<Score*> m_scoreList;
	void sortScores();
	void processSelection();
public:
	ScoreList();
	void addScore(int move, std::string name, int level);
	void displayScore();
	virtual ~ScoreList();
};



#endif /* SCORELIST_H_ */
