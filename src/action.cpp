#include "action.h"

Action::Action(String resourcePath) {
	fetchImages(resourcePath);
}

void Action::fetchImages(String folderPath) {
	vector<String> files;
	glob(folderPath, files, false);

	for(int i = 0; i < files.size(); ++i) {
		Mat img = imread(files[i]);
		std::string text = files[i];
		std::string outputFilePath = text.replace(2, 8, "output");
		ImageWrapper* iw = new ImageWrapper(img, outputFilePath);
		images.push_back(iw);
	}
}

void Action::start() {
	for(int i = 0; i < images.size(); ++i) {
		ImageWrapper* currentImage = images[i];
		currentImage->performClassification();
		currentImage->writeImage();
	}
}

Action::~Action() {
	for(int i = 0; i < images.size(); ++i) {
		delete images[i];
	}
}