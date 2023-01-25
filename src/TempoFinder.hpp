#pragma once

class TempoFinder {
public:
	TempoFinder(double tempo, int Bf);
	~TempoFinder();
	double calculateTempo();
private:
	double tempo;
	int Bf;
	double* acf;
	double* combValues;

	void zeroArrays();
	double calculateMeanThreshold(double* arr, int beg, int end);
	void autocorrelationFunction(double* resDFSamples, int Bf);
	void combTemplate(double periocidy);
};