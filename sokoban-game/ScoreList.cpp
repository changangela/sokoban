/*
 * ScoreList.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: Angela
 */

#include "ScoreList.h"

ScoreList::ScoreList() {
	// TODO Auto-generated constructor stub
	m_selectedLevel = 0;
	m_scoreList.push_back(new Score(9, "Angela",0));
	m_scoreList.push_back(new Score(7, "Bob",0));
	m_scoreList.push_back(new Score(13, "Dylan",0));
	m_scoreList.push_back(new Score(19, "Chris",0));
	m_scoreList.push_back(new Score(11, "Ryan",0));
	m_scoreList.push_back(new Score(10, "Nick",0));

	m_scoreList.push_back(new Score(29, "Angela",1));
	m_scoreList.push_back(new Score(17, "Bob",1));
	m_scoreList.push_back(new Score(26, "Dylan",1));
	m_scoreList.push_back(new Score(28, "Chris",1));
	m_scoreList.push_back(new Score(31, "Ryan",1));
	m_scoreList.push_back(new Score(40, "Nick",1));

	m_scoreList.push_back(new Score(91, "Angela",2));
	m_scoreList.push_back(new Score(74, "Bob",2));
	m_scoreList.push_back(new Score(132, "Dylan",2));
	m_scoreList.push_back(new Score(87, "Chris",2));
	m_scoreList.push_back(new Score(113, "Ryan",2));
	m_scoreList.push_back(new Score(106, "Nick",2));

	m_scoreList.push_back(new Score(210, "Angela",3));
	m_scoreList.push_back(new Score(174, "Bob",3));
	m_scoreList.push_back(new Score(136, "Dylan",3));
	m_scoreList.push_back(new Score(198, "Chris",3));
	m_scoreList.push_back(new Score(117, "Ryan",3));
	m_scoreList.push_back(new Score(109, "Nick",3));

	m_scoreList.push_back(new Score(192, "Angela",4));
	m_scoreList.push_back(new Score(197, "Bob",4));
	m_scoreList.push_back(new Score(213, "Dylan",4));
	m_scoreList.push_back(new Score(319, "Chris",4));
	m_scoreList.push_back(new Score(311, "Ryan",4));
	m_scoreList.push_back(new Score(410, "Nick",4));
}

ScoreList::~ScoreList() {
	// TODO Auto-generated destructor stub
}

void ScoreList::addScore(int move, std::string name, int level) {
	m_scoreList.push_back(new Score(move, name, level));
}
void ScoreList::sortScores() {
	// a selection sort algorithm
	int max = 0;
	int unsorted = 0;
	while (unsorted < (signed int)m_scoreList.size()) {
		max = unsorted;
		for (int i = unsorted; i < (signed int)m_scoreList.size(); i++) {
			if (m_scoreList[i]->getMoves() > m_scoreList[max]->getMoves()) {
				max = i;
			}
		}

		Score* tempScore = new Score(*m_scoreList[max]);
		m_scoreList[max] = new Score(*m_scoreList[unsorted]);
		m_scoreList[unsorted] = new Score(*tempScore);
		unsorted++;
	}
}
void ScoreList::displayScore() {
	// scores are printed by order of first added
	std::cout << "-----------------------------\n";
	std::cout << "            SCORES           \n";
	std::cout << "-----------------------------\n";
	cout << "Level 1                     1\n";
	cout << "Level 2                     2\n";
	cout << "Level 3                     3\n";
	cout << "Level 4                     4\n";
	cout << "Level 5                     5\n";
	cout << "-----------------------------\n";

	processSelection();

	// the scores were sorted using an selection sort
	sortScores();

	// user selected level scores were printed
	std::cout << "Name\t\tLevel\tMoves\n";
	for (std::vector<Score*>::iterator score = m_scoreList.begin();
			score != m_scoreList.end(); ++score) {
		if ((*score)->getLevel() == m_selectedLevel) {
			std::cout << (*score)->getName() << "\t\t"
					<< (*score)->getLevel() + 1 << "\t" << (*score)->getMoves()
					<< endl;
		}
	}
	std::cout << "Press Enter key to continue..." << endl;
}
void ScoreList::processSelection() {
	// processes the user selected level
	cout << "Selection:                  ";
	cin >> m_selectedLevel;
	if (cin.fail()) {
		// if the input was not a valid integer
		cin.clear();
		cin.ignore();
		cout << "Invalid selection." << endl;
		processSelection(); // recursive call
	} else {
		switch (m_selectedLevel) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			// fall through switch case
			m_selectedLevel--;
			break;
		default:
			cout << "Invalid selection." << endl;
			processSelection(); // recursive call
		}
	}
}
