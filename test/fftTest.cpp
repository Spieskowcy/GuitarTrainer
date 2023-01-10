#pragma once
#include "gtest/gtest.h"

#include "FFT.hpp"

TEST(fftTest, arrayOfOnesTest){
    constexpr int PROBES_NO = 32;

    // PREPARE
    float expected[PROBES_NO] = { 32 };     // expected: { 32, 0, 0, 0, 0... }

    auto data = Segment(PROBES_NO);
    for(int i = 0; i < PROBES_NO; i++){
        data.rawSignal[i] = 1;
    }


    auto fft = FFT(PROBES_NO);

    // TEST
    fft.Calculate(&data);


    // CHECK RESULTS
    for(int i = 0; i < PROBES_NO; i++){
        EXPECT_EQ(expected[i], data.afterFFT[i]);
    }
}

