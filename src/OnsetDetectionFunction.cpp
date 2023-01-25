#include "OnsetDetectionFunction.hpp"
#include <cmath>

OnsetDetectionFunction::OnsetDetectionFunction(int frameProbesNo, int hopProbesNo, int DFSamplesSize){
	this-> frameProbesNo = frameProbesNo;
	this->hopProbesNo = hopProbesNo;
	frameProbes = new double[frameProbesNo];
	this->DFSamplesSize = DFSamplesSize;
	DFSamples = new double[DFSamplesSize];
	zeroArrays();							// initialise arrays with 0 (to prevent random values)
	prevSum = 0;
}

OnsetDetectionFunction::~OnsetDetectionFunction(){
	delete[] frameProbes;
	delete[] DFSamples;
}

double OnsetDetectionFunction::calculateDF(double* newProbes){
	double sum = 0;
	addNewProbesToFrame(newProbes);				// remember new signal probes
	
	//calculate sum of squares of probes in frame
	for(int i = 0; i < frameProbesNo; i++){
		sum += pow(frameProbes[i], 2);
	}

	double probe = sum - prevSum;				// calculate difference of new and previous sums
	prevSum = sum;								// remember new sum for the future
	
	// if difference is greater then 0 then return it else return 0
	addNewDFSample((probe > 0) ? probe : 0.0);	
	return (probe>0) ? probe : 0;
}

void OnsetDetectionFunction::addNewProbesToFrame(double* newProbes){
	// remove first hopProbesNo samples and add new hopProbesNo samples at the end of array
	for(int i=0; i < (frameProbesNo - hopProbesNo); i++){
		frameProbes[i] = frameProbes[i + hopProbesNo];
		frameProbes[i + hopProbesNo] = newProbes[i];
	}
}

void OnsetDetectionFunction::addNewDFSample(double sample) {
	// remove oldest sample to prepare space for new one
	for (int i = 0; i < DFSamplesSize - 1; i++) {
		DFSamples[i] = DFSamples[i + 1];
	}
	// add new sample at the end of array
	DFSamples[DFSamplesSize - 1] = sample;
}

void OnsetDetectionFunction::zeroArrays(){
	// initialise all arrays with zeros to prevent random numbers during calculations
	for(int i = 0; i < frameProbesNo; i++){
		frameProbes[i] = 0;
		if (i < DFSamplesSize) DFSamples[i] = 0.0;
	}
}


