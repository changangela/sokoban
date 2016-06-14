/*
 * Box.h
 *
 *  Created on: Jun 12, 2016
 *      Author: Angela
 */

#ifndef BOX_H_
#define BOX_H_

#include "Moveable.h"

class Box: public Moveable {
	bool m_inHole;
public:
	static int numBox;
	static int numInHole;
	Box();
	Box(int row, int column);
	Box(int row, int column, bool inHole);
	bool isInHole();
	void setInHole(bool inHole);
	static int getNumBox();
	static void resetNumBox();
	static int getNumInHole();
	static void setNumInHole(int num);
	char toString();
	virtual ~Box();
};

#endif /* BOX_H_ */
