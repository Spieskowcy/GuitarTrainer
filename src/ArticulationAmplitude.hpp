#pragma once
#include "Segment.hpp"
#include <vector>
#include <memory>


namespace Amplitude {

struct Sound {
	Sound(float val, float freq, float diff, int seg_id) : val(val), freq(freq), diff(diff), segment_id(seg_id) {};
	float val;
	float freq;
	float diff;
	int segment_id;
};
class ArticulationAmplitude {

typedef struct MaxValue {
	float value = 0.0f;
	float freq = 0.0f;
};

public:
	ArticulationAmplitude(int probesNo) :probesNo(probesNo) {};
	
	std::vector<Sound> sounds;
	void Calculate(std::vector<std::shared_ptr<Segment>> segments);
private:


	MaxValue GetMax(Segment &segment);
	int probesNo;
	float THRESHOLD = 0;
};

}
