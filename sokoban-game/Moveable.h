/*
 * Moveable.h
 *
 *  Created on: Jun 12, 2016
 *      Author: Angela
 */

#ifndef MOVEABLE_H_
#define MOVEABLE_H_

#include "Unit.h"
#include "Offset.h"

class Moveable:public Unit {
public:
	Moveable();
	Moveable(int row, int column);
	void move(Offset offset);
	virtual ~Moveable();
};

#endif /* MOVEABLE_H_ */
