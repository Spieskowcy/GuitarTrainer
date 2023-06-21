#include "ArticulationLength.hpp"
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>

void ArticulationLength::CalculateLength() 
{
    for(int i=0; i<total; i++)
    {
        if(i<numberOfSamples)
            continue;
        
        if(absRaw[i]>=startingThreshold && i-startIndex > ATTACK_TIME)
        { 
            if(currentSound!=nullptr)
            {
                SaveSound(i);
            }
            notHearableSoundCounter=0;
            hearable = true;
            currentSound = new Sound();
            startIndex=i;
        }
        else if(absRaw[i]>=CONTINUE_THRESHOLD && hearable)
        {
            notHearableSoundCounter=0;
        }
        else if(absRaw[i]<CONTINUE_THRESHOLD && hearable)
        {
            notHearableSoundCounter++;
            if(notHearableSoundCounter > COUNTER_THRESHOLD)
            {
                hearable = false;
                SaveSound(i);
            }
        }
    }
    if(hearable)
    {
        SaveSound(total-1);
    }
}

void ArticulationLength::SaveSound(int currentIndex)
{
    if(currentIndex-startIndex<MIN_LENGTH)
    {
        return;
    }
    currentSound->beginIndex=startIndex;
    currentSound->beginSegment=startIndex/numberOfSamples;
    currentSound->endIndex=currentIndex;
    currentSound->endSegment=currentIndex/numberOfSamples;
    currentSound->soundIndex=currentSoundIndex;
    sounds.push_back(currentSound);
    currentSound++;
    currentSound=nullptr;
}

void ArticulationLength::ReadSegments() {
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
    

    absRaw = new float[total];
    int currentIndex = 0;
    for(int i=0; i<totalSegments; i++)
    {
        Segment* currentSegment = segments.front();
        for(int j=0; j<numberOfSamples; j++)
        {
            absRaw[currentIndex] = abs(currentSegment->rawSignal[j]);
            currentIndex++;
        }
        segments.pop();
        delete currentSegment;
    }
    startingThreshold = *std::max_element(absRaw+numberOfSamples,absRaw+total-numberOfSamples) * (1-RELATIVE_OFFSET_TO_MAX);
}

ArticulationLength::ArticulationLength(int numberOfSamples, std::string filePath)
{
    this->numberOfSamples = numberOfSamples;
    this->filePath = filePath;
    ReadSegments();
    CalculateLength();
}

ArticulationLength::~ArticulationLength()
{
    delete absRaw;
}