#pragma once
#include "gtest/gtest.h"


#include "ArticulationLength.hpp"
#include "FFT.hpp"
#include <iostream>
#include <string.h>

TEST(articulationLengthCheck, 1){
	Segment seg(1024);
	ArticulationLength articulationLength(1024, "../rsc/a_p.wav");

	ASSERT_EQ(articulationLength.sounds[0]->beginIndex,96);
	ASSERT_EQ(articulationLength.sounds[0]->endIndex,18637);
}


