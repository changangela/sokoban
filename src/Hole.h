/*
 * Hole.h
 *
 *  Created on: Jun 12, 2016
 *      Author: Angela
 */

#ifndef HOLE_H_
#define HOLE_H_

#include "Unit.h"

class Hole:public Unit {
protected:
	bool m_covered;
public:
	Hole();
	Hole(int row, int column);
	bool isCovered();
	void setCovered(bool covered);
	char toString();
	virtual ~Hole();
};

#endif /* HOLE_H_ */
