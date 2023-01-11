#pragma once
#include "gtest/gtest.h"

#include "WavHandler.h"
#include "FFT.hpp"

#include <iostream>

TEST(e2eTest, temp){
    size_t probeSize = 1024;
    WavHandler wav_hdr("../rsc/test3.wav");
    Segment seg(probeSize);
    FFT fft(probeSize);

    ASSERT_EQ(wav_hdr.wavHeader.fmt[0], 'f');
    ASSERT_EQ(wav_hdr.wavHeader.fmt[1], 'm');
    ASSERT_EQ(wav_hdr.wavHeader.fmt[2], 't');
    while(!wav_hdr.FinishedReading())
    {
        wav_hdr.ReadRawData(&seg);
        fft.Calculate(&seg);
    }
}