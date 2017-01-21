#ifndef _5_GR_CLASS_H
#define _5_GR_CLASS_H

#include "base.h"
#include "element.h"

class _5GrClass: public Base {
private:
	static const double areaMin = 0.106;
	static const double areaMax = 0.113;
	Element* calibrationElement;

public:
	_5GrClass(Element*);
	bool checkIsThisClass(Element&);
};

#endif