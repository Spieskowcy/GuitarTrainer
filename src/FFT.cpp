#include "FFT.hpp"

FFT::FFT(int probesNo){
    status = DftiCreateDescriptor(&descriptorHandle, DFTI_SINGLE, DFTI_REAL, 1, probesNo);
    status = DftiSetValue(descriptorHandle, DFTI_PLACEMENT, DFTI_NOT_INPLACE);
    status = DftiCommitDescriptor(descriptorHandle);
}

void FFT::Calculate(Segment* seg){
    status = DftiComputeForward(descriptorHandle, seg->rawSignal, seg->afterFFT);
}

FFT::~FFT(){
    status = DftiFreeDescriptor(&descriptorHandle);
}
