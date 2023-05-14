#include "Rhythm.hpp"
#include <math.h>

Rhythm::Rhythm() {
	this->frameIndex = 0;
	this->energyHistoryBuffer = new float[FRAMES];
	ZeroEnergyHistoryBuffer();
}

Rhythm::~Rhythm() {
	delete[] this->energyHistoryBuffer;
}

void Rhythm::ReadSegments(char* filePath) {
	WavHandler handler(filePath);
	while (!handler.FinishedReading())
	{
		Segment *seg = new Segment(NUM_OF_SAMPLES);
		handler.ReadRawData(seg);
		this->segments.push_back(seg);
	}
}

float Rhythm::CalculateEnergy(Segment* data) {
	float energy = 0.0;
	for (int i = 0; i < data->probesNo; i++) {
		energy += pow(data->rawSignal[i], 2)/NUM_OF_SAMPLES;
	}
	return energy;
}

float Rhythm::CalculateAverageEnergy() {
	float constant = 1.0 / ((float)FRAMES);
	float sum = 0.0;

	for (int i = 0; i < FRAMES; i++) {
		sum += pow(this->energyHistoryBuffer[i], 2);
	}

	return constant * sum;
}

float Rhythm::CalculateVariance(float averageEnergy) {
	float constant = 1.0 / ((float)FRAMES);
	float sum = 0.0;
	float difference = 0.0;

	for (int i = 0; i < FRAMES; i++) {
		difference = this->energyHistoryBuffer[i] - averageEnergy;
		sum += pow(difference, 2);
	}

	return constant * sum;
}

void Rhythm::SearchForBeats() {
	for (Segment* seg : segments) {
		float energy = CalculateEnergy(seg);
		float avgEnergy = CalculateAverageEnergy();
		float V = CalculateVariance(avgEnergy);
		float C = -0.0025714 * V + 1.5142857;
		ShiftEnergyHistoryBuffer();
		this->energyHistoryBuffer[0] = energy;
		if (energy > C * avgEnergy) {
			float time = CalculateTime();
			this->beatTime.push_back(time);
			if(time >= 0.4 && this->beatTime.size() > 1){
                        	RemoveOldBeatTimes();
       	                	CalculateLocalBPM();
                	}
		}
		this->frameIndex++;
	}
}

void Rhythm::CalculateLocalBPM() {
	float delta = 0.0;
	int beatCounter = this->beatTime.size() - 1;
 	for (float time : this->beatTime){
    		float tmp = floor(time);
		delta += (time-tmp);	
	}	
	int bpm = 60.0 / (delta / beatCounter);
	this->calculatedBPMs.push_back(bpm);
}

int Rhythm::CalculateBPM() {
	SearchForBeats();
	int sum = 0.0;
	for (int BPM : this->calculatedBPMs) {
		sum += BPM;
	}
	int val = sum / this->calculatedBPMs.size();
	return val;
}



void Rhythm::ZeroEnergyHistoryBuffer() {
	for (int i = 0; i < FRAMES; i++) {
		this->energyHistoryBuffer[i] = 0;
	}
}

void Rhythm::ShiftEnergyHistoryBuffer() {
	for (int i = FRAMES-1; i > 0; i--) {
		this->energyHistoryBuffer[i] = this->energyHistoryBuffer[i - 1];
	}
}

void Rhythm::RemoveOldBeatTimes() {
	float latestBeatTime = this->beatTime.back();
	int toRemCtr = 0;	
	for (float time : this->beatTime) {
		if (latestBeatTime - time > 1.0) {
			toRemCtr++;
		}
		else {
			break;
		}
	}
	for(int i = 0; i < toRemCtr; i++){
		this->beatTime.pop_front();
	}
}

//returns time in seconds
float Rhythm::CalculateTime() {
	float oneFrameTime = 1.0 / (float) FRAMES;
	float time = oneFrameTime * this->frameIndex;
	return time;
}


