#pragma once
#include "Segment.hpp"
#include <vector>
#include <memory>

struct SoundAmplitude {
	SoundAmplitude(float val, float freq, float diff, int seg_id) : val(val), freq(freq), diff(diff), segment_id(seg_id) {};
	float val;
	float freq;
	float diff;
	int segment_id;
};

class ArticulationAmplitude {
public:
	ArticulationAmplitude(int probesNo) :probesNo(probesNo) {};
	
	std::vector<SoundAmplitude> sounds;
	void Calculate(std::vector<std::shared_ptr<Segment>> segments);
private:
	int probesNo;
	float THRESHOLD = 0;
};
