#include "OnsetDetectionFunction.hpp"
#include <cmath>

OnsetDetectionFunction::OnsetDetectionFunction(int frameProbesNo, int hopProbesNo){
	this-> frameProbesNo = frameProbesNo;
	this->hopProbesNo = hopProbesNo;
	frameProbes = new double[frameProbesNo];
	zeroFrameProbes();
	prevSum = 0;
}

OnsetDetectionFunction::~OnsetDetectionFunction(){
	delete[] frameProbes;
}

double OnsetDetectionFunction::calculateDF(double* newProbes){
	double sum = 0;
	addNewProbesToFrame(newProbes);
	for(int i = 0; i < frameProbesNo; i++){
		sum += pow(frameProbes[i], 2);
	}
	double probe = sum - prevSum;
	prevSum = sum;
	return (probe>0) ? probe : 0;
}

void OnsetDetectionFunction::addNewProbesToFrame(double* newProbes){
	for(int i=0; i < (frameProbesNo - hopProbesNo); i++){
		frameProbes[i] = frameProbes[i + hopProbesNo];
		frameProbes[i + hopProbesNo] = newProbes[i];
	}
}

void OnsetDetectionFunction::zeroFrameProbes(){
	for(int i = 0; i < frameProbesNo; i++){
		frameProbes[i] = 0;
	}
}


