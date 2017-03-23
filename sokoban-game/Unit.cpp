/*
 * Unit.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: Angela
 */

#include "Unit.h"

Unit::Unit() {
	// TODO Auto-generated constructor stub
	m_column=0;
	m_row=0;
}

Unit::Unit(int row, int column){
	// overloaded constructor
	m_row=row;
	m_column=column;
}

Unit::~Unit() {
	// TODO Auto-generated destructor stub
}

// encapsulation for the m_row and m_column private variables
int Unit::getRow(){
	return m_row;
}
int Unit::getColumn(){
	return m_column;
}
void Unit::setRow(int row){
	m_row=row;
}
void Unit::setColumn(int column){
	m_column=column;
}
char Unit::toString(){
	// default char return value for virtual function
	return ' ';
}
