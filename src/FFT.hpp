#ifndef _FFT_H_
#define _FFT_H_

#include "mkl.h"
#include "Segment.hpp"

class FFT {
public:
    FFT(int probesNo);
    ~FFT();
    
    /// @brief Calculating FFT on segment
    /// @param seg - input/output data. Input data is seg->rawSignal, output data is afterFFT.
    void Calculate(Segment* seg);
private:
    DFTI_DESCRIPTOR_HANDLE descriptorHandle;
    int status;
};

#endif
