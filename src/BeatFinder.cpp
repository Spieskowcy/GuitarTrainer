#include "BeatFinder.hpp"
#include <cmath>

BeatFinder::BeatFinder(int cumulativeScoreSize){
	this->cumulativeScoreSize = cumulativeScoreSize;
	this->cumulativeScore = new double[cumulativeScoreSize];
	double tmp = (double)cumulativeScoreSize * 120 / 44100;
	this->beatPeriod = 60.0 / tmp;
	this->alpha = 0.9;
	this->eta = 5;

	// initilise cumulativeScore array with zeros (to prevent random values during calculating first set of cumulative scores)
	for (int i = 0; i < cumulativeScoreSize; i++) {
		this->cumulativeScore[i] = 0.0;
	}
}

BeatFinder::~BeatFinder() {
	delete[] cumulativeScore;
}

double BeatFinder::getLastCumulativeScore() {
	return cumulativeScore[cumulativeScoreSize - 1];
}

void BeatFinder::addNewCumulativeScore(double cumScore) {
	// remove oldest cumulative score to prepare space for new one
	for (int i = 0; i < cumulativeScoreSize - 1; i++) {
		cumulativeScore[i] = cumulativeScore[i + 1];
	}
	// add new cumulative score at the end of array
	cumulativeScore[cumulativeScoreSize - 1] = cumScore;
}

void BeatFinder::calculateCumulativeScore(double sample) {
	int minV = -round(2 * beatPeriod);			// minimum value of v (-2*beatPeriod)
	int maxV = -round(beatPeriod / 2);			// maximum value of v (-beatPeriod/2)
	double* W = new double[maxV - minV + 1];	// array for transition weighting

	// calculate log-Gaussian transition weighting
	for (int v = minV; v < maxV + 1; v++) {
		W[v - minV] = exp((-pow(eta * log(-v / beatPeriod), 2)) / 2);
	}

	double max = 0, tmp = 0;
	int v = 0;

	// calculate max(W(v)*cumulativeScore(m+v)
	for (int i = cumulativeScoreSize + minV; i <= cumulativeScoreSize + maxV; i++) {
		tmp = cumulativeScore[i] * W[v++];
		if (tmp > max) max = tmp;
	}

	double score = ((1.0 - alpha) * sample) + (alpha * max);

	addNewCumulativeScore(score);
	delete[] W;
}
