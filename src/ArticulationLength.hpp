#pragma once
#include "Segment.hpp"
#include "WavHandler.h"
#include <vector>

struct Sound {
    int beginIndex;
    int beginSegment;
    int endIndex;
    int endSegment;
    int soundIndex;
    
    int Length()
    {
        return endIndex-beginIndex;
    }
};

class ArticulationLength {
private:
    const float RELATIVE_OFFSET_TO_MAX=0.15;
    float startingThreshold = 0;
    const float CONTINUE_THRESHOLD = 150000000;
    const int COUNTER_THRESHOLD = 100;
    const int MIN_LENGTH = 2000;
    const int ATTACK_TIME = 200;

    int numberOfSamples;
    int total = 0;
    float* absRaw;
    float* raw;
    std::string filePath;

    int currentSoundIndex = 0;
    int notHearableSoundCounter = 0;
    bool hearable = false;
    Sound* currentSound = nullptr;
    int startIndex = 0;

    void SaveSound(int currentIndex);
public:
    std::vector<Sound*> sounds;

    void CalculateLength();
    void ReadSegments();
    ArticulationLength(int numberOfSamples, std::string filePath);
    ~ArticulationLength();
};
