#pragma once
#include "gtest/gtest.h"

#include "WavHandler.h"
#include "FFT.hpp"
#include "ToneModule.hpp"

#include <iostream>
#include <cmath>

std::unique_ptr<float[]> sinA(float ampl, float freq, float sampleRate, float theta, size_t size){
    std::unique_ptr<float[]> arr = std::make_unique<float[]>(size);
    float dt = 0;
    for(int i = 0; i < size; i++){
        arr[i] = ampl * std::sin(2*M_PI * freq * dt + theta);
        dt += sampleRate;
    }
    return arr;
}

TEST(toneTest, sinATest){
    size_t probeSize = 1024;
    Segment seg(probeSize);
    FFT fft(probeSize);

    seg.rawSignal = sinA(1, 440, 1.0/44100, 0, probeSize).release();
    fft.Calculate(&seg);

    ToneModule tone(probeSize);

    Tone output = tone.process(&seg);

    ASSERT_EQ(output.getSound(), Note::A);
}

TEST(toneTest, sinCTest){
    size_t probeSize = 1024 * 4;
    Segment seg(probeSize);
    FFT fft(probeSize);

    seg.rawSignal = sinA(1, 261, 1.0/44100, 0, probeSize).release();
    fft.Calculate(&seg);

    ToneModule tone(probeSize);

    Tone output = tone.process(&seg);

    ASSERT_EQ(output.getSound(), Note::C);
}

TEST(toneTest, wavATest){
    size_t probeSize = 1024 * 16;
    WavHandler wav_hdr("../rsc/a_p.wav");
    Segment seg(probeSize);
    FFT fft(probeSize);
    ToneModule tone(probeSize);

    while(!wav_hdr.FinishedReading()) {
        wav_hdr.ReadRawData(&seg);
        fft.Calculate(&seg);

        Tone output = tone.process(&seg);
        if(output.getFrequency() > 0 && output.getFrequency() < 1000){
            ASSERT_EQ(output.getSound(), Note::A);
        }
    }
}
