#pragma once
#include "gtest/gtest.h"

#include "WavHandler.h"
#include "FFT.hpp"

#include <iostream>

TEST(e2eTest, temp){
    size_t probeSize = 1024;
    WavHandler wav_hdr("test3.wav");
    Segment seg(probeSize);
    FFT fft(probeSize);
    size_t count = 0;
    while(!wav_hdr.FinishedReading())
    {
        wav_hdr.ReadRawData(&seg);
        fft.Calculate(&seg);
        for(int i=0; i < probeSize; i++)
        {
            std::cout<<count<<" " << seg.rawSignal[i] <<" "<<seg.afterFFT[i]<<std::endl;
            count++;
        }
        std::cout<<std::endl;
    }
}