/*
 * Wall.h
 *
 *  Created on: Jun 13, 2016
 *      Author: Angela
 */

#ifndef WALL_H_
#define WALL_H_

#include "Unit.h"

class Wall :public Unit{
public:
	Wall(int row, int column);
	Wall();
	char toString();
	virtual ~Wall();
};

#endif /* WALL_H_ */
