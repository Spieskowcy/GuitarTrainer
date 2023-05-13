#pragma once
#include "gtest/gtest.h"


#include "Rhythm.hpp"
#include <iostream>
#include <string.h>

TEST(xdTest, 120bpm){
        char filePath[20] = "../rsc/120bpm.wav";
	Rhythm rhythmM;
	rhythmM.ReadSegments(filePath);
	int val = rhythmM.CalculateBPM();

        ASSERT_NEAR(val, 120, 5);

}

TEST(xdTest, 150bpm){
        char filePath[20] = "../rsc/150bpm.wav";
        Rhythm rhythmM;
        rhythmM.ReadSegments(filePath);
        int val = rhythmM.CalculateBPM();

        ASSERT_NEAR(val, 150, 5);

}


