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
    const float STARTING_THRESHOLD = 250000000;
    const float CONTINUE_THRESHOLD = 210000000;
    const int COUNTER_THRESHOLD = 100;
    const int MIN_LENGTH = 1000;
    const int ATTACK_TIME = 1000;

    int numberOfSamples;
    int total = 0;
    float* absRaw;
    float* raw;
    std::string filePath;

    int currentSoundIndex = 0;
    int notHearableSoundCounter = 0;
    bool hearable = false;
    Sound* currentSound = nullptr;
    int startIndex;

    void SaveSound(int currentIndex);
public:
    std::vector<Sound*> sounds;

    void CalculateLength();
    void ReadSegments();
    ArticulationLength(int numberOfSamples, std::string filePath);
    ~ArticulationLength();
};
