#ifndef _1_GR_CLASS_H
#define _1_GR_CLASS_H

#include "base.h"
#include "element.h"

class _1GrClass: public Base {
private:
	static const double areaMin = 0.06;
	static const double areaMax = 0.079;
	Element* calibrationElement;

public:
	_1GrClass(Element*);
	bool checkIsThisClass(Element&);
};

#endif