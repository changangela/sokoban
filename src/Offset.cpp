/*
 * Offset.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: Angela
 */

#include "Offset.h"

Offset::Offset() {
	// TODO Auto-generated constructor stub
	m_x = 0;
	m_y = 0;
}
Offset::Offset(int x, int y) {
	// overloaded construction

	// m_x variable can only take a value of -1, 0, or +1
	if (x > 0)
		m_x = +1;
	else if (x < 0)
		m_x = -1;
	else
		m_x = 0;


	if(y>0)
		m_y=+1;
	else if (y<0)
		m_y=-1;
	else
		m_y=0;
}
int Offset::getX() {
	return m_x;
}
int Offset::getY() {
	return m_y;
}
Offset::~Offset() {
	// TODO Auto-generated destructor stub
}

