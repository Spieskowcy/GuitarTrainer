#pragma once

class BeatFinder {
public:
	BeatFinder(int cumulativeScoreNumber);
	~BeatFinder();
	double getLastCumulativeScore();					// returns newest value from cumulativeScore array
	double* getCumulativeScore();						// returns whole cumulativeScore array
	void calculateCumulativeScore(double sample);		// calculates new cumulative score based on df sample
private:
	double alpha;										// balance between new info in DF and past info
	double eta;											// tightness of the transition weighting
	double beatPeriod;									// period of time between two last beats
	int cumulativeScoreSize;							// number of cumulative scores stored in cumulativeScore array
	double* cumulativeScore;							// array with cumulative scores

	void addNewCumulativeScore(double cumScore);		// adds new cumulative score to cumulativeScore array

};
