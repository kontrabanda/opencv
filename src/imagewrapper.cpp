#include "imagewrapper.h"

ImageWrapper::ImageWrapper(Mat img, string saveFilePath) {
	this->saveFilePath = saveFilePath;
	image = img.clone();
	segmentation = new Segmentation(image);
}

void ImageWrapper::performClassification() {
	image = segmentation->getSegmentedImage();

	ElementGetter eg(image);
	vector<Element*> vec = eg.getElements();
	cout << "Ilość elementów: " << vec.size() << endl;
	
	for(int i = 0; i < vec.size(); ++i) {
		
		vec[i]->drawElement(image);

		cout << "M1: " << vec[i]->getM1() << endl;
		cout << "M3: " << vec[i]->getM3() << endl;
		cout << "M7: " << vec[i]->getM7() << endl;
		cout << endl;
	}

}

void ImageWrapper::writeImage() {
	cout << "Saving image: " << saveFilePath << endl;
	imwrite(saveFilePath, image);
}

ImageWrapper::~ImageWrapper() {
	delete segmentation;
}