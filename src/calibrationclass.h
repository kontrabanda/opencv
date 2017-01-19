#ifndef CALIBRATION_CLASS_H
#define CALIBRATION_CLASS_H

#include "base.h"
#include "element.h"

class CalibrationClass: public Base {
	
public:
	CalibrationClass();
	bool checkIsThisClass(Element&);
};

#endif