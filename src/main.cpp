#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <math.h>
#include <iostream>
#include <vector>
#include <glob.h>

#include "action.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Action* action = new Action("./resource/*.JPG");
	action->start();

    waitKey();

    delete action;
}