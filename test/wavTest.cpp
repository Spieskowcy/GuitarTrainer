#pragma once
#include "gtest/gtest.h"

#include "WavHandler.h"
#include "FFT.hpp"

#include <iostream>

TEST(wavTest, temp){
    size_t probeSize = 1024;
    WavHandler wav_hdr("../rsc/a_p.wav");
    Segment seg(probeSize);
    std::ifstream correctData;
    float data;
    float allowedError = 10000;
    correctData.open("../rsc/wavTestData.txt");

    ASSERT_EQ(wav_hdr.wavHeader.fmt[0], 'f');
    ASSERT_EQ(wav_hdr.wavHeader.fmt[1], 'm');
    ASSERT_EQ(wav_hdr.wavHeader.fmt[2], 't');
    while(!wav_hdr.FinishedReading())
    {
        wav_hdr.ReadRawData(&seg);
        for(int i=0; i<probeSize; i++)
        {
            correctData>>data;
            ASSERT_NEAR(seg.rawSignal[i], data, allowedError);
        }
    }
    correctData.close();
}