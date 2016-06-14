
#ifndef SPACE_H_
#define SPACE_H_

#include "Unit.h"

class Space :public Unit{
public:
	Space();
	Space(int row, int column);
	char toString();
	virtual ~Space();


};

#endif /* SPACE_H_ */
