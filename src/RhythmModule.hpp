#pragma once
#include "OnsetDetectionFunction.hpp"

class RhythmModule{
public:
	RhythmModule(int frameProbesNo, int hopProbesNo);
	~RhythmModule();
	void processFrame(double* frame);
	double getLastCumulativeScore();

private:
	double alpha;		// balance between new info in DF and past info
	double beatPeriod, tempo;
	double eta;		// tightness of the transition weighting
//	double m0;
	OnsetDetectionFunction df;
	int DFBuffSize;
	double* cumulativeScore;
	bool beatIsPresent;
	int beatCtr;
	
	void zeroArrays();
	void addNewCumulativeScore(double cumScore);
	void calculateCumulativeScore(double sample);
};
