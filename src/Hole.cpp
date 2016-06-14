/*
 * Hole.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: Angela
 */

#include "Hole.h"

Hole::Hole() :
		Unit() {
	// TODO Auto-generated constructor stub
	m_covered = false;
}
Hole::Hole(int row, int column) :
		Unit(row, column) {
	m_covered = false;
}

// encapsulation of private member variables
bool Hole::isCovered(){
	return m_covered;
}
void Hole::setCovered(bool covered){
	m_covered=covered;
}

char Hole::toString(){
	// returns the character representation of Hole object
	if(!m_covered)
		return '.';
	else
		return '*';
}
Hole::~Hole() {
	// TODO Auto-generated destructor stub
}

