#pragma once
#include "gtest/gtest.h"


#include "ArticulationLength.hpp"
#include "FFT.hpp"
#include <iostream>
#include <string.h>

TEST(articulationLengthCheck, 1){
	Segment seg(1024);
	ArticulationLength articulationLength(1024, "../rsc/a_p.wav");

	ASSERT_EQ(articulationLength.sounds[0]->beginIndex,1698);
	ASSERT_EQ(articulationLength.sounds[0]->endIndex,26035);
}
