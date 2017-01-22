#ifndef _1_ZL_CLASS_H
#define _1_ZL_CLASS_H

#include "base.h"
#include "element.h"

class _1ZlClass: public Base {
private:
	static const double areaMin = 0.148;
	static const double areaMax = 0.162;
	Element* calibrationElement;

public:
	_1ZlClass(Element*);
	bool checkIsThisClass(Element&);
};

#endif