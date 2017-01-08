#include "imagewrapper.h"

ImageWrapper::ImageWrapper(Mat img, string saveFilePath) {
	this->saveFilePath = saveFilePath;
	image = img.clone();
	segmentation = new Segmentation(image);
}

void ImageWrapper::performClassification() {
	image = segmentation->getSegmentedImage();
}

void ImageWrapper::writeImage() {
	cout << "Saving image: " << saveFilePath << endl;
	imwrite(saveFilePath, image);
}

ImageWrapper::~ImageWrapper() {
	delete segmentation;
}