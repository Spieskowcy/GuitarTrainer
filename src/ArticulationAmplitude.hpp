#pragma once
#include "Segment.hpp"
#include <vector>
#include <memory>

namespace ArticulationAmplitude {

struct Sound {
	Sound(float val, float freq, float diff, int seg_id) : val(val), freq(freq), diff(diff), segment_id(seg_id) {};
	float val;
	float freq;
	float diff;
	int segment_id;
};

class Module {
public:
	Module(int probesNo) : probesNo(probesNo) {};
	
	std::vector<Sound> sounds;
	void Calculate(std::vector<std::shared_ptr<Segment>> segments);
private:
	struct MaxValue {
		float value = 0.0f;
		float freq = 0.0f;
	};

	MaxValue GetMax(Segment &segment);
	int probesNo;
	float THRESHOLD = 0;
};

}
