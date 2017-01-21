#ifndef _2_ZL_CLASS_H
#define _2_ZL_CLASS_H

#include "base.h"
#include "element.h"

class _2ZlClass: public Base {
private:
	static const double areaMin = 0.137;
	static const double areaMax = 0.145;
	Element* calibrationElement;

public:
	_2ZlClass(Element*);
	bool checkIsThisClass(Element&);
};

#endif