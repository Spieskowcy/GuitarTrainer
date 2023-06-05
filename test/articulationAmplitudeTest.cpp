#pragma once
#include "gtest/gtest.h"


#include "ArticulationAmplitude.hpp"
#include <iostream>
#include <string.h>
#include <vector>
#include <memory>

std::shared_ptr<Segment> GetSegment(float firstValue, int probes_no) {
	auto result = std::make_shared<Segment>(probes_no);
	for(int i = 0; i < probes_no; i++){
		result->afterFFT[i] = 0;
	}
	result->afterFFT[0] = firstValue;
	return result;
}

TEST(articulationAmplitudeTest, FewTonesOneByOne){
	constexpr int PROBES_NO = 32;
	constexpr int SEGMENTS_NO = 20;
	std::vector<std::shared_ptr<Segment>> segments;

	for(int i = 0; i < 10; i++){
		segments.push_back(GetSegment(10-i, PROBES_NO));
	}
	for(int i = 10; i < SEGMENTS_NO; i++){
		segments.push_back(GetSegment(15-i, PROBES_NO));
	}

	ArticulationAmplitude module(PROBES_NO);
	module.Calculate(segments);

	ASSERT_EQ(2, module.sounds.size());
	ASSERT_EQ(SEGMENTS_NO, segments.size());
}


