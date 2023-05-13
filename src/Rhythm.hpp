#pragma once
#include "Segment.hpp"
#include "WavHandler.h"
#include <list>
using namespace std;

#define NUM_OF_SAMPLES 1024
#define FRAMES 43
#define SENSIBILITY 1.3

class Rhythm {
public:
    Rhythm();
    ~Rhythm();

    void ReadSegments(char* filePath);
    int CalculateBPM();

private:
    float* energyHistoryBuffer;
    int frameIndex;
    list<float> beatTime;
    list<Segment*> segments;
    list<int> calculatedBPMs;

    float CalculateEnergy(Segment* data);
    float CalculateAverageEnergy();
    float CalculateVariance(float averageEnergy);
    void SearchForBeats();
    void CalculateLocalBPM();

    void ZeroEnergyHistoryBuffer();
    void ShiftEnergyHistoryBuffer();
    void RemoveOldBeatTimes();
    float CalculateTime(); 
};
