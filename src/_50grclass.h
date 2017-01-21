#ifndef _50_GR_CLASS_H
#define _50_GR_CLASS_H

#include "base.h"
#include "element.h"

class _50GrClass: public Base {
private:
	static const double areaMin = 0.122;
	static const double areaMax = 0.126;
	Element* calibrationElement;

public:
	_50GrClass(Element*);
	bool checkIsThisClass(Element&);
};

#endif