#include "Space.h"

Space::Space(): Unit(){
	// TODO Auto-generated constructor stub

}
Space::Space(int row, int column):Unit(row, column){

}
Space::~Space() {
	// TODO Auto-generated destructor stub
}

char Space::toString(){
	return ' ';
}
