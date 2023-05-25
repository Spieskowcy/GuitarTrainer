#include "ArticulationLength.hpp"
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>

void ArticulationLength::CalculateLength() 
{
    Sound* currentSound = nullptr;
    int startIndex;
    for(int i=0; i<total; i++)
    {
        if(i<50)
            continue;
        if(absRaw[i]>=CONTINUE_THRESHOLD && hearable)
        {
            notHearableSoundCounter=0;
        }
        else if(absRaw[i]>=STARTING_THRESHOLD && !hearable)
        {
            notHearableSoundCounter=0;
            hearable = true;
            currentSound = new Sound();
            startIndex=i;
        }
        else if(absRaw[i]<CONTINUE_THRESHOLD && hearable)
        {
            notHearableSoundCounter++;
            if(notHearableSoundCounter > COUNTER_THRESHOLD)
            {
                currentSound->beginIndex=startIndex;
                currentSound->beginSegment=startIndex/numberOfSamples;
                currentSound->endIndex=i;
                currentSound->endSegment=i/numberOfSamples;
                currentSound->soundIndex=currentSoundIndex;
                sounds.push_back(currentSound);

                hearable = false;
                currentSound++;
            }
        }
    }
}

void ArticulationLength::ReadSegments() {
    std::ofstream out("xd.txt");
	WavHandler handler(filePath.c_str());
    
    std::queue<Segment*> segments;
    
    int totalSegments=0;
	while (!handler.FinishedReading())
	{
		Segment* seg = new Segment(numberOfSamples);
		handler.ReadRawData(seg);
		total+=numberOfSamples;
        totalSegments++;
        segments.push(seg);
	}
    
    raw = new float[total];
    absRaw = new float[total];
    int currentIndex = 0;
    for(int i=0; i<totalSegments; i++)
    {
        Segment* currentSegment = segments.front();
        for(int j=0; j<numberOfSamples; j++)
        {
            raw[currentIndex] = currentSegment->rawSignal[j];
            absRaw[currentIndex] = abs(raw[currentIndex]);
            out<<std::fixed<<raw[currentIndex]<<std::endl;
            currentIndex++;
        }
        segments.pop();
        delete currentSegment;
    }
}

ArticulationLength::ArticulationLength(int numberOfSamples, std::string filePath)
{
    this->numberOfSamples = numberOfSamples;
    this->filePath = filePath;
    absRaw = new float[this->numberOfSamples];
    ReadSegments();
    CalculateLength();
}

ArticulationLength::~ArticulationLength()
{
    delete absRaw;
}