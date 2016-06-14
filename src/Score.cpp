/*
 * Score.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: Angela
 */

#include "Score.h"

Score::Score() {
	// TODO Auto-generated constructor stub
	m_level = 0;
	m_moves = 0;
}
Score::Score(int moves, std::string name, int level) {
	// overloaded constructor
	m_moves = moves;
	m_name = name;
	m_level = level;
}
void Score::setMoves(int moves) {
	m_moves = moves;
}
int Score::getMoves() {
	return m_moves;
}
void Score::setLevel(int level) {
	m_level = level;
}
int Score::getLevel(){
	return m_level;
}
void Score::setName(std::string name) {
	m_name = name;
}
std::string Score::getName() {
	return m_name;
}

Score::~Score() {
	// TODO Auto-generated destructor stub
}

