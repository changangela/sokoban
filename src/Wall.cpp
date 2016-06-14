/*
 * Wall.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: Angela
 */

#include "Wall.h"

Wall::Wall():Unit() {
	// TODO Auto-generated constructor stub

}
Wall::Wall(int row, int column):Unit(row, column){

}
char Wall::toString(){
	return '#';
}
Wall::~Wall() {
	// TODO Auto-generated destructor stub
}

