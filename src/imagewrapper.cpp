#include "imagewrapper.h"

ImageWrapper::ImageWrapper(Mat img, string saveFilePath) {
	this->saveFilePath = saveFilePath;
	image = img.clone();
	inputImage = img.clone();
	segmentation = new Segmentation(image);
}

void ImageWrapper::performClassification() {
	image = segmentation->getSegmentedImage();

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
	delete segmentation;
}