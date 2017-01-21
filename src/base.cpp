#include "base.h"

Base::Base() {

}

bool Base::checkIsThisClass(Element& el) {
	return false;
}

bool Base::isCoinShape(Element& el) {
	double M1 = el.getM1();
	double M2 = el.getM2();

	if(M1 > M1_MIN && M1 < M1_MAX &&
		M2 > M2_MIN && M2 < M2_MAX) {
		return true;
	}

	return false;
}