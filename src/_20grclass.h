#ifndef _20_GR_CLASS_H
#define _20_GR_CLASS_H

#include "base.h"
#include "element.h"

class _20GrClass: public Base {
private:
	static const double areaMin = 0.097;
	static const double areaMax = 0.12;
	Element* calibrationElement;

public:
	_20GrClass(Element*);
	bool checkIsThisClass(Element&);
};

#endif