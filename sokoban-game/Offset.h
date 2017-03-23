/*
 * Offset.h
 *
 *  Created on: Jun 12, 2016
 *      Author: Angela
 */

#ifndef OFFSET_H_
#define OFFSET_H_

class Offset {
private:
	int m_x;
	int m_y;
public:
	Offset();
	Offset(int x,int y);
	int getX();
	int getY();
	virtual ~Offset();
};

#endif /* OFFSET_H_ */
