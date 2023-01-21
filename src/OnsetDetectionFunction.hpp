#pragma once

class OnsetDetectionFunction{
public:
	OnsetDetectionFunction(int frameProbesNo, int hopProbesNo);
	double calculateDF(double* newProbes);
	~OnsetDetectionFunction();
private:
	int frameProbesNo;
	int hopProbesNo;
	double prevSum;
	double* frameProbes;

	void addNewProbesToFrame(double* newProbes);
	void zeroFrameProbes();
};
