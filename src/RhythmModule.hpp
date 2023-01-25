#pragma once
#include "OnsetDetectionFunction.hpp"
#include "BeatFinder.hpp"

class RhythmModule{
public:
	RhythmModule(int frameProbesNo, int hopProbesNo);
	~RhythmModule();
	void processFrame(double* frame);			// searches for beat and finds tempo between them
	double getLastCumulativeScore();			// returns latest calculated cumulative score 

private:
	double tempo;
	OnsetDetectionFunction df;
	BeatFinder bFinder;
	bool beatIsPresent;
	int beatCtr;
};
