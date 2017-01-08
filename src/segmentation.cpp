#include "segmentation.h"

Segmentation::Segmentation(Mat& img): image(img) {
	filterAvg(10);
	int colors[3] = {-1, 254, -1};
	filterColors(colors);
}


void Segmentation::filterAvg(int threshold) {
	Mat_<Vec3b> _I = image;

	for(int i = 0; i < _I.rows; ++i) {
		for(int j = 0; j < _I.cols; ++j) {
			int avg = (_I(i, j)[0] + _I(i, j)[1] + _I(i, j)[2])/3;
			
			for(int c = 0; c < 3; ++c) {
				int value = image.at<Vec3b>(i,j)[c];

				if(avg + threshold > value && avg - threshold < value) {
					image.at<Vec3b>(i,j)[c] = 255;					
				} else {
					image.at<Vec3b>(i,j)[c] = 0;
				}
			}
		}
	}

	image = _I;
}

void Segmentation::filterColors(int* colors) {
	Mat_<Vec3b> _I = image;

	for(int i = 0; i < _I.rows; ++i) {
		for(int j = 0; j < _I.cols; ++j) {
			int blue = _I(i, j)[0];
			int green = _I(i, j)[1];
			int red = _I(i, j)[2];

			if(blue > colors[0] && green > colors[1] && red > colors[2]) {
				_I(i, j)[0] = 255;
				_I(i, j)[1] = 255;
				_I(i, j)[2] = 255;
			} else {
				_I(i, j)[0] = 0;
				_I(i, j)[1] = 0;
				_I(i, j)[2] = 0;
			}
		}
	}

	image = _I;
}

int Segmentation::getValidateColor(int color) {
	if(color > 255) {
		return 255;
	} else if(color < 0) {
		return 0;
	} else {
		return color;
	}
}

Mat Segmentation::getSegmentedImage() {
	return image;
}