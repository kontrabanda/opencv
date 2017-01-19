#include "classifier.h"

Classifier::Classifier(vector<Element*>* calibrationElements, Mat& img): image(img) {
	//TODO tutaj dodac wybieranie elementu kalibrującego
	//cout << endl << _20_GR << endl << endl;
	

	calibrationElement = getCalibrationElement(calibrationElements);
	calibrationElement->print();
	calibrationElement->drawElement(image);
}

Element* Classifier::getCalibrationElement(vector<Element*>* calibrationElements) {
	Element* result = (*calibrationElements)[0];
	CalibrationClass calibrationClass;
	
	for(int i = 1; i < (*calibrationElements).size(); ++i) {
		Element* currEl = (*calibrationElements)[i];

		if(currEl->getArea() > result->getArea()) {
			result = (calibrationClass.checkIsThisClass(*currEl)) ? currEl : result;
		}
	}

	return new Element(result->points);
}

Classifier::~Classifier() {
	delete calibrationElement;
}