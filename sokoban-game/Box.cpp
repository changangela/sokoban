#include "Box.h"

int Box::numBox = 0; // static initialization of numBox variable
int Box::numInHole=0; // static initialization of numInHole variable
Box::Box() :
		Moveable() {
	// TODO Auto-generated constructor stub
	m_inHole = false;
	numBox++;
}
Box::Box(int row, int column) :
		Moveable(row, column) {
	// overloaded constructor
	m_inHole = false;
	numBox++;
}
Box::Box(int row, int column, bool inHole):Moveable(row, column){
	// overloaded constructor
	m_inHole=inHole;
	if(inHole){
		numInHole++;
	}
	numBox++;
}
bool Box::isInHole() {
	return m_inHole;
}
void Box::setInHole(bool inHole) {
	m_inHole = inHole;
}
int Box::getNumBox() {
	return numBox;
}
void Box::resetNumBox() {
	numBox = 0;
}
int Box::getNumInHole(){
	return numInHole;
}
void Box::setNumInHole(int num){
	numInHole=num;
}
char Box::toString() {
	// returns the character '$' to represent a Box on console
	if (!m_inHole)
		return '$';
	else
		return '*';
}
Box::~Box()
{
	// TODO Auto-generated destructor stub
}
