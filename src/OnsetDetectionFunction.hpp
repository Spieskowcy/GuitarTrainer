#pragma once

class OnsetDetectionFunction{
public:
	OnsetDetectionFunction(int frameProbesNo, int hopProbesNo, int DFSamplesSize);
	double calculateDF(double* newProbes);			// calculates new DF sample
	~OnsetDetectionFunction();
private:
	int frameProbesNo;			// number of probes in frame
	int hopProbesNo;			// number of new probes added to frame
	int DFSamplesSize;			// number of remebered DF samples
	double prevSum;				// previous sum
	double* frameProbes;		// array that stores signal probes
	double* DFSamples;			// array that stores DF samples

	void addNewProbesToFrame(double* newProbes);	// adds new signal probes to frame
	void addNewDFSample(double sample);				// adds new DF sample to array
	void zeroArrays();								// initializes frameProbes and DFSamples with 0
};
