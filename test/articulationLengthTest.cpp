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

TEST(articulationLengthUseCase, 2){
	Segment seg(1024);
	ArticulationLength articulationLength1(1024, "../rsc/cw1.wav");
	ArticulationLength articulationLength2(1024, "../rsc/cw1.wav");

	ASSERT_EQ(articulationLength1.sounds.size(), articulationLength2.sounds.size());
	for(int i=0; i<articulationLength1.sounds.size(); i++)
	{
		ASSERT_EQ(articulationLength1.sounds[i]->Length(), articulationLength2.sounds[i]->Length());
	}
}
