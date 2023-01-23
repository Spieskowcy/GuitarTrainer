#include "RhythmModule.hpp"
#include <cmath>
#include <iostream>

RhythmModule::RhythmModule(int frameProbesNo, int hopProbesNo)
: df(frameProbesNo, hopProbesNo)
{
	this->alpha = 0.9;
	this->eta = 5;
	this->tempo = 120;
	this->DFBuffSize = hopProbesNo;
	this->cumulativeScore = new double[DFBuffSize];
	double tmp = hopProbesNo*tempo/44100;	
	this->beatPeriod = 60 / tmp;
	//this->beatPeriod = 43;
	this->beatIsPresent = false;
	zeroArrays();
}

RhythmModule::~RhythmModule(){
	delete[] cumulativeScore;

}
void RhythmModule::zeroArrays(){
	for(int i = 0; i < DFBuffSize; i++){
		cumulativeScore[i] = 0.0;
	}
}

void RhythmModule::addNewCumulativeScore(double cumScore){
	for(int i = 0; i < DFBuffSize - 1; i++){
		cumulativeScore[i] = cumulativeScore[i+1];
	}
	cumulativeScore[DFBuffSize-1] = cumScore;
}

double RhythmModule::getLastCumulativeScore(){
	return cumulativeScore[DFBuffSize-1];
}

void RhythmModule::processFrame(double* frame){
	double sample = df.calculateDF(frame);
	return calculateCumulativeScore(sample);
	//if((--beatCtr) == 0){
	//	beatIsPresent = true;
//	}
}

void RhythmModule::calculateCumulativeScore(double sample){
	int minV = -round(2 * beatPeriod);
	int maxV = -round(beatPeriod / 2);
	double* W = new double[maxV - minV + 1];

	for(int v = minV; v <  maxV+1; v++){
		W[v-minV] = exp((-pow(eta * log(-v / beatPeriod),2)) / 2);
	}

	double max = 0, tmp = 0;
	int v = 0;

	for(int i = DFBuffSize + minV; i <= DFBuffSize + maxV; i++){
		tmp = cumulativeScore[i] * W[v++];
		if(tmp > max) max = tmp;
	}
	
	double score = ((1-alpha) * sample) + (alpha * max );

	addNewCumulativeScore( score );
	delete[] W;
}





