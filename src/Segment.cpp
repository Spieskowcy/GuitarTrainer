#include "Segment.hpp"    

Segment::Segment(int probesNo){
    this->probesNo = probesNo;
    rawSignal = new float[probesNo];
    afterFFT = new float[probesNo];
};

Segment::~Segment(){
    delete[] rawSignal;
    delete[] afterFFT;
};

