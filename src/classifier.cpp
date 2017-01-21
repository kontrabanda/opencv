#include "classifier.h"

Classifier::Classifier(vector<Element*>* calibrationElements, Mat& img): image(img) {
	//TODO tutaj dodac wybieranie elementu kalibrującego
	//cout << endl << _20_GR << endl << endl;
	
	classifiedElements = new vector<Element*>[10];

	calibrationElement = getCalibrationElement(calibrationElements);
	//calibrationElement->print();
	calibrationElement->drawElement(image);

	initClassesCheck();
}

void Classifier::initClassesCheck() {
	classesCheck[_1_GR] = new _1GrClass(calibrationElement);
	classesCheck[_2_GR] = new _2GrClass(calibrationElement);
	classesCheck[_5_GR] = new _5GrClass(calibrationElement);
	classesCheck[_10_GR] = new _10GrClass(calibrationElement);
	classesCheck[_20_GR] = new _20GrClass(calibrationElement);
	classesCheck[_50_GR] = new _50GrClass(calibrationElement);
	classesCheck[_1_ZL] = new _1ZlClass(calibrationElement);
	classesCheck[_2_ZL] = new _2ZlClass(calibrationElement);
	classesCheck[_5_ZL] = new _5ZlClass(calibrationElement);
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

void Classifier::classify(Element* el) {
	vector<int> result; 
	int index = -1;
	//classifiedElements[_10_GR].push_back(el);

	for(int i = 0; i < CLASSES_COUNT; ++i) {
		if(classesCheck[i]->checkIsThisClass(*el)) {
			result.push_back(i);
			index = i;
		}
	}

	if(result.size() == 1) {
		classifiedElements[index].push_back(el);
	}
}

void Classifier::printItemsInfo(int index, Mat& image) {
	/*vector<Element*> selectedVec = classifiedElements[index];
	cout << selectedVec.size() << endl;

	for(int i = 0; i < selectedVec.size(); ++i) {
		selectedVec[i]->drawElement(image);
	}*/

	cout << "1 GR: " << classifiedElements[_1_GR].size() << endl;
	cout << "2 GR: " << classifiedElements[_2_GR].size() << endl;
	cout << "5 GR: " << classifiedElements[_5_GR].size() << endl;
	cout << "10 GR: " << classifiedElements[_10_GR].size() << endl;
	cout << "20 GR: " << classifiedElements[_20_GR].size() << endl;
	cout << "50 GR: " << classifiedElements[_50_GR].size() << endl;
	cout << "1 ZL: " << classifiedElements[_1_ZL].size() << endl;
	cout << "2 ZL: " << classifiedElements[_2_ZL].size() << endl;
	cout << "5 ZL: " << classifiedElements[_5_ZL].size() << endl;
}

Classifier::~Classifier() {
	delete calibrationElement;
	delete[] classifiedElements;

	for(int i = 0; i < CLASSES_COUNT; ++i) {
		delete classesCheck[i];
	}
}