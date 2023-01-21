#pragma once
#include "Segment.hpp"
#include "Tone.hpp"

class ToneModule{
public:
 explicit ToneModule(int probeSize, float sampleRate);

 Tone process(Segment* in);
private:
 int probeSize;
 float sampleRate;
};

