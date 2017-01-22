#include "imagewrapper.h"

ImageWrapper::ImageWrapper(Mat img, string saveFilePath) {
	this->saveFilePath = saveFilePath;
	image = img.clone();
	inputImage = img.clone();
	
	calibrationSegmentation = new Segmentation(image);
	contentSegmentation = new Segmentation(image);
}

void ImageWrapper::performClassification() {
	performCalibrationSegmentation();
	performContentSegmentation();
}

void ImageWrapper::performCalibrationSegmentation() {
	cout << "Perform Calibration Segmentation" << endl;
	int colorsMin[3] = {-1, -1, 90};
	int colorsMax[3] = {256, 130, 256};

	calibrationSegmentation->filterColorsMin(colorsMin);
	calibrationSegmentation->filterColorsMax(colorsMax);
	calibrationSegmentation->binarization();

	calibrationImage = calibrationSegmentation->getSegmentedImage();

	for(int i = 0; i < 25; ++i) {
		contentSegmentation->closing();
	}

	ElementGetter eg(calibrationImage, inputImage);
	calibrationElements = eg.getElements();
	classifier = new Classifier(calibrationElements, calibrationImage);
}

void ImageWrapper::performContentSegmentation() {
	cout << "Perform Content Segmentation" << endl;
	int colors[3] = {-1, 254, -1};
	int bt[2] = {-80, 20};
	int gt[2] = {-20, 20};
	int rt[2] = {-80, 80};

	contentSegmentation->filterAvg(bt, gt, rt);
	image = contentSegmentation->getSegmentedImage();
	
	//contentSegmentation->filterColorsMin(colors);
	contentSegmentation->binarization();

	// for(int i = 0; i < 10; ++i) {
	// 	contentSegmentation->opening();
	// }

	image = contentSegmentation->getSegmentedImage();

	ElementGetter eg(image, inputImage);
	findedElements = eg.getElements();
	//cout << "Ilość elementów: " << (*findedElements).size() << endl;
	
	for(int i = 0; i < (*findedElements).size(); ++i) {
		classifier->classify((*findedElements)[i]);
	}

	// 10GR
	classifier->printItemsInfo(image);
}

void ImageWrapper::writeImage() {
	cout << "Saving image: " << saveFilePath << endl;
	imwrite(saveFilePath, image);
	string calibrationPath = saveFilePath.substr(0, saveFilePath.length() - 4);
	cout << "Saving calibratrion image: " << saveFilePath << endl;
	imwrite(calibrationPath + "calibration.JPG", calibrationImage);
	cout << endl;
}

ImageWrapper::~ImageWrapper() {
	for(int i = 0; i < (*calibrationElements).size(); ++i) {
		delete (*calibrationElements)[i];
	}

	delete calibrationElements;

	for(int i = 0; i < (*findedElements).size(); ++i) {
		delete (*findedElements)[i];
	}

	delete findedElements;

	delete contentSegmentation;
	delete calibrationSegmentation;
	delete classifier;
}