#ifndef _5_ZL_CLASS_H
#define _5_ZL_CLASS_H

#include "base.h"
#include "element.h"

class _5ZlClass: public Base {
private:
	static const double areaMin = 0.156;
	static const double areaMax = 0.178;
	Element* calibrationElement;

public:
	_5ZlClass(Element*);
	bool checkIsThisClass(Element&);
};

#endif