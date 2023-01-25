#include "RhythmModule.hpp"
#include <cmath>
#include <iostream>
using namespace std;

RhythmModule::RhythmModule(int frameProbesNo, int hopProbesNo)
: df(frameProbesNo, hopProbesNo, 512), bFinder(hopProbesNo)
{
	this->tempo = 120;
	this->beatIsPresent = false;
}

RhythmModule::~RhythmModule(){}


double RhythmModule::getLastCumulativeScore() {
	return bFinder.getLastCumulativeScore();
}

void RhythmModule::processFrame(double* frame){
	double sample = df.calculateDF(frame);
	bFinder.calculateCumulativeScore(sample);
}




