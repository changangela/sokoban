/*
 * Unit.h
 *
 *  Created on: Jun 12, 2016
 *      Author: Angela
 */

#ifndef UNIT_H_
#define UNIT_H_

class Unit {
protected:
	int m_row;
	int m_column;
public:
	Unit();
	Unit(int row, int column);
	int getRow();
	void setRow(int row);
	int getColumn();
	void setColumn(int column);
	virtual char toString();
	virtual ~Unit();
};

#endif /* UNIT_H_ */
