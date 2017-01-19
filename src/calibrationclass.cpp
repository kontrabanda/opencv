#include "calibrationclass.h"

CalibrationClass::CalibrationClass() {

}

bool CalibrationClass::checkIsThisClass(Element& el) {
	Color avgColor = el.getAvgColor();

	if(avgColor.r > 150) {
		return true;
	} else {
		return false;
	}
}