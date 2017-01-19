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


	//performContentSegmentation();

	
}

void ImageWrapper::performCalibrationSegmentation() {
	cout << "Perform Calibration Segmentation" << endl;
	int colorsMin[3] = {-1, -1, 110};
	int colorsMax[3] = {256, 130, 256};

	calibrationSegmentation->filterColorsMin(colorsMin);
	calibrationSegmentation->filterColorsMax(colorsMax);
	calibrationSegmentation->binarization();

	calibrationImage = calibrationSegmentation->getSegmentedImage();

	for(int i = 0; i < 25; ++i) {
		contentSegmentation->closing();
	}

	ElementGetter eg(calibrationImage, inputImage);
	vector<Element*> vec = eg.getElements();
	vec[0]->print();
	classifier = new Classifier(&vec, calibrationImage);

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
	string calibrationPath = saveFilePath.substr(0, saveFilePath.length() - 4);
	cout << "Saving calibratrion image: " << saveFilePath << endl;
	imwrite(calibrationPath + "calibration.JPG", calibrationImage);
	cout << endl;
}

ImageWrapper::~ImageWrapper() {
	delete contentSegmentation;
	delete calibrationSegmentation;
	delete classifier;
}