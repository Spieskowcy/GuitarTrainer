#include "TempoFinder.hpp"
#include <cmath>

TempoFinder::TempoFinder(double tempo, int Bf) {
	this->tempo = tempo;
	this->Bf = Bf;
	this->acf = new double[Bf];
	this->combValues = new double[Bf];
	zeroArrays();
}

TempoFinder::~TempoFinder() {
	delete[] acf;
	delete[] combValues;
}

void TempoFinder::zeroArrays() {
	for (int i = 0; i < Bf; i++) {
		acf[i] = 0.0;
		combValues[i] = 0.0;
	}
}

double TempoFinder::calculateMeanThreshold(double* arr, int beg, int end) {
	if (end - beg <= 0) return 0;
	double sum = 0;
	for (int i = beg; i < end; i++) {
		sum += arr[i];
	}
	return sum / (end - beg);
}

void TempoFinder::autocorrelationFunction(double* resDFSamples, int Bf) {
	for (int l = 0; l < Bf; l++) {
		double sum = 0.0;
		for (int m = 0; m < Bf; m++) {
			sum += resDFSamples[m];
		}
		acf[l] = sum / (l+1);
	}
}

void TempoFinder::combTemplate(double periocidy){
	int maxP = 4;			// max number of comb elements
	for (int l = 0; l < Bf; l++) {
		double sum = 0.0;
		for (int p = 1; p <= maxP; p++) {
			for (int v = 1 - p; v <= p - 1; v++) {

			}
		}
	}
}

double TempoFinder::calculateTempo() {
	return 0;
}