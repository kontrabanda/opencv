#ifndef _2_ZL_CLASS_H
#define _2_ZL_CLASS_H

#include "base.h"
#include "element.h"

class _2ZlClass: public Base {
private:
	static const double areaMin = 0.134;
	static const double areaMax = 0.16;
	Element* calibrationElement;

public:
	_2ZlClass(Element*);
	bool checkIsThisClass(Element&);
};

#endif