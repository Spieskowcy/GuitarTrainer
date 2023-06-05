#include "ArticulationAmplitude.hpp"

void ArticulationAmplitude::Calculate(std::vector<std::shared_ptr<Segment>> segments){
	float lastMax=0;
	int seg_id = 0;
	for(auto seg : segments){
		// get max value in segment
		float max = 0;
		float freq = 0;
		for(int i = 0; i < probesNo; i++){
			float probe = seg->afterFFT[i];
			if(probe > max){
				freq = i;
				max = probe;
			}
		}

		// add new sound if new sound detected
		if(sounds.size() == 0 && abs(max) > THRESHOLD){
			sounds.push_back(SoundAmplitude(max, freq, 0, seg_id));
		}
		else if(sounds.size() > 0){
			auto lastSound = sounds[sounds.size()-1];
			if(max > lastMax){
				sounds.push_back(SoundAmplitude(max, freq, std::abs(lastSound.val-max), seg_id));
			}
		}
		lastMax = max;
		seg_id++;
	}
}

