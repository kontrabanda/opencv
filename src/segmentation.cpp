#include "segmentation.h"

Segmentation::Segmentation(Mat& img): image(img) {
	filterAvg(10);

	int colors[3] = {-1, 254, -1};
	filterColors(colors);

	for(int i = 0; i < 10; ++i) {
		closing();
	}
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

void Segmentation::dilatation() {
	struct Dilatation {
		static int getPixelValue(Mat_<Vec3b>& image, int y, int x) {
			if(y < 0 || x < 0 || y >= image.rows || x >= image.cols) {
				return 0;
			}

			return image(y, x)[0];
		}

		static bool checkDilatation(Mat_<Vec3b>& image, int i, int j) {
			if(image(i, j)[0] == 255) {
				return true;
			}			

			int topPixelValue = getPixelValue(image, i + 1, j);
			int bottomPixelValue = getPixelValue(image, i - 1, j);
			int leftPixelValue = getPixelValue(image, i, j - 1);
			int rightPixelValue = getPixelValue(image, i, j + 1);

			return (topPixelValue == 255 || bottomPixelValue == 255 || leftPixelValue == 255 || rightPixelValue == 255);
		}

	};

	Mat_<Vec3b> _I = image;
	Mat_<Vec3b> result = image.clone();

	for(int i = 0; i < result.rows; ++i) {
		for(int j = 0; j < result.cols; ++j) {
			if(Dilatation::checkDilatation(_I, i, j)) {
				result(i, j)[0] = 255;
				result(i, j)[1] = 255;
				result(i, j)[2] = 255;
			} else {
				result(i, j)[0] = 0;
				result(i, j)[1] = 0;
				result(i, j)[2] = 0;
			}
		}
	}

	image = result;
}

void Segmentation::erosion() {
	struct Erosion {
		static int getPixelValue(Mat_<Vec3b>& image, int y, int x) {
			if(y < 0 || x < 0 || y >= image.rows || x >= image.cols) {
				return 255;
			}

			return image(y, x)[0];
		}

		static bool checkErosion(Mat_<Vec3b>& image, int i, int j) {
			if(image(i, j)[0] == 0) {
				return true;
			}			

			int topPixelValue = getPixelValue(image, i + 1, j);
			int bottomPixelValue = getPixelValue(image, i - 1, j);
			int leftPixelValue = getPixelValue(image, i, j - 1);
			int rightPixelValue = getPixelValue(image, i, j + 1);

			return (topPixelValue == 0 || bottomPixelValue == 0 || leftPixelValue == 0 || rightPixelValue == 0);
		}

	};

	Mat_<Vec3b> _I = image;
	Mat_<Vec3b> result = image.clone();

	for(int i = 0; i < result.rows; ++i) {
		for(int j = 0; j < result.cols; ++j) {
			if(Erosion::checkErosion(_I, i, j)) {
				result(i, j)[0] = 0;
				result(i, j)[1] = 0;
				result(i, j)[2] = 0;
			} else {
				result(i, j)[0] = 255;
				result(i, j)[1] = 255;
				result(i, j)[2] = 255;
			}
		}
	}

	image = result;
}

void Segmentation::opening() {
	erosion();
	dilatation();
}

void Segmentation::closing() {
	dilatation();
	erosion();
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