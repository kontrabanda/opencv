#ifndef _2_GR_CLASS_H
#define _2_GR_CLASS_H

#include "base.h"
#include "element.h"

class _2GrClass: public Base {
private:
	static const double areaMin = 0.086;
	static const double areaMax = 0.098;
	Element* calibrationElement;

public:
	_2GrClass(Element*);
	bool checkIsThisClass(Element&);
};

#endif