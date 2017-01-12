#include "invariants.h"

Invariants::Invariants(Mat& img): image(img) {
	/*smallInvariants['m10'] = 0;
	smallInvariants['m01'] = 0;
	smallInvariants['m11'] = 0;
	smallInvariants['m20'] = 0;
	smallInvariants['m02'] = 0;*/
}

void Invariants::computeSmallInvariants() {
	Mat_<Vec3b> _I = image;

	for(int i = 0; i < _I.rows; ++i) {
		for(int j = 0; j < _I.cols; ++j) {
			//double x = ///intesywność piksela (kolory na trzy)

			/*smallInvariants['m10'] += i * j * x;
			smallInvariants['m01'] += 0;
			smallInvariants['m11'] += 0;
			smallInvariants['m20'] += 0;
			smallInvariants['m02'] += 0;*/
		}
	}

	image = _I;
}