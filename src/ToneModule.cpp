#include "ToneModule.hpp"
#include<cmath>

ToneModule::ToneModule(int probeSize):probeSize(probeSize){ }

Tone ToneModule::process(Segment* seg){
    int maxi = 0;
    float max = std::abs(seg->afterFFT[0]);
    for(int i = 0; i < probeSize; i++){
        if(max < std::abs(seg->afterFFT[i])){
            max = std::abs(seg->afterFFT[i]);
            maxi = i;
        }
    }
    return (double)maxi * (44100.0 / probeSize / 2.0);
}
