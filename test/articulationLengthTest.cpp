#pragma once
#include "gtest/gtest.h"


#include "ArticulationLength.hpp"
#include "FFT.hpp"
#include <iostream>
#include <string.h>


TEST(articulationLengthTest, 1){
	Segment seg(1024);
	ArticulationLength articulationLength1(1024, "../rsc/cw1.wav");
	ArticulationLength articulationLength2(1024, "../rsc/cw1.wav");
	
	ASSERT_EQ(articulationLength1.sounds.size(), articulationLength2.sounds.size());
	for(int i=0; i<articulationLength1.sounds.size(); i++)
	{
		ASSERT_EQ(articulationLength1.sounds[i]->Length(), articulationLength2.sounds[i]->Length());
	}
}

TEST(articulationLengthCw, 1){
	Segment seg(1024);
	ArticulationLength articulationLength1(1024, "../rsc/cw1.wav");
	ArticulationLength articulationLength2(1024, "../rsc/cw1test.wav");
	ASSERT_NE(articulationLength1.sounds.size(), 0);
	ASSERT_NE(articulationLength2.sounds.size(), 0);
}

TEST(articulationLengthCw, 2){
	Segment seg(1024);
	ArticulationLength articulationLength1(1024, "../rsc/cw2.wav");
	ArticulationLength articulationLength2(1024, "../rsc/cw2test.wav");
	ASSERT_NE(articulationLength1.sounds.size(), 0);
	ASSERT_NE(articulationLength2.sounds.size(), 0);
}

TEST(articulationLengthCw, 3){
	Segment seg(1024);
	ArticulationLength articulationLength1(1024, "../rsc/cw3.wav");
	ArticulationLength articulationLength2(1024, "../rsc/cw3rhythm.wav");
	ASSERT_NE(articulationLength1.sounds.size(), 0);
	ASSERT_NE(articulationLength2.sounds.size(), 0);
}
