#ifndef _10_GR_CLASS_H
#define _10_GR_CLASS_H

#include "base.h"
#include "element.h"

class _10GrClass: public Base {
private:
	static const double areaMin = 0.078;
	static const double areaMax = 0.090;
	Element* calibrationElement;

public:
	_10GrClass(Element*);
	bool checkIsThisClass(Element&);
};

#endif