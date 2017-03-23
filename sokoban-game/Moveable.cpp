/*
 * Moveable.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: Angela
 */

#include "Moveable.h"

Moveable::Moveable():Unit() {
	// TODO Auto-generated constructor stub

}
Moveable::Moveable(int row, int column):Unit(row, column){
	// overloaded constructor
}
Moveable::~Moveable() {
	// TODO Auto-generated destructor stub
}
void Moveable::move(Offset offset){
	// virtual function that will be overriden
		m_row += offset.getX();
		m_column += offset.getY();
}
