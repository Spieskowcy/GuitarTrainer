#pragma once
#include "Segment.hpp"
#include "Tone.hpp"

class ToneModule{
public:
 explicit ToneModule(int probeSize);

 Tone process(Segment* in);
private:
 int probeSize;
};

