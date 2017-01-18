#include "imagewrapper.h"

ImageWrapper::ImageWrapper(Mat img, string saveFilePath) {
	this->saveFilePath = saveFilePath;
	image = img.clone();
	inputImage = img.clone();
	calibrationSegmentation = new Segmentation(image);
	contentSegmentation = new Segmentation(image);
}

void ImageWrapper::performClassification() {
	//performContentSegmentation();
	performCalibrationSegmentation();

	
}

void ImageWrapper::performCalibrationSegmentation() {
	int colorsMin[3] = {-1, -1, 140};
	int colorsMax[3] = {256, 70, 256};

	calibrationSegmentation->filterColorsMin(colorsMin);
	calibrationSegmentation->filterColorsMax(colorsMax);
	calibrationSegmentation->binarization();

	image = calibrationSegmentation->getSegmentedImage();

	ElementGetter eg(image, inputImage);
	vector<Element*> vec = eg.getElements();
	cout << "Ilość elementów: " << vec.size() << endl;
	
	for(int i = 0; i < vec.size(); ++i) {
		vec[i]->drawElement(image);
		vec[i]->print();
	}
}

void ImageWrapper::performContentSegmentation() {
	int colors[3] = {-1, 254, -1};
	image = contentSegmentation->getSegmentedImage();

	contentSegmentation->filterAvg(10);
	contentSegmentation->filterColorsMin(colors);
	contentSegmentation->binarization();

	for(int i = 0; i < 10; ++i) {
		contentSegmentation->closing();
	}

	ElementGetter eg(image, inputImage);
	vector<Element*> vec = eg.getElements();
	cout << "Ilość elementów: " << vec.size() << endl;
	
	for(int i = 0; i < vec.size(); ++i) {
		vec[i]->drawElement(image);
		vec[i]->print();
	}
}

void ImageWrapper::writeImage() {
	cout << "Saving image: " << saveFilePath << endl;
	imwrite(saveFilePath, image);
	cout << endl;
}

ImageWrapper::~ImageWrapper() {
	delete contentSegmentation;
	delete calibrationSegmentation;
}