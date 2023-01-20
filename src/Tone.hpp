#pragma once
#include "Note.hpp"

class Tone{
public:
    Tone(float freq):freq(freq){}

    Note getSound();
    float getOffset();
    float getFrequency();
private:
    float freq;
};


