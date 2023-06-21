#include "gtest/gtest.h"


#include "ArticulationAmplitude.hpp"
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
	//Arange
	constexpr int PROBES_NO = 32;
	constexpr int SEGMENTS_NO = 20;
	std::vector<std::shared_ptr<Segment>> segments;

	for(int i = 10; i >= 0; i--){
		segments.push_back(GetSegment(i, PROBES_NO));
	}

	segments.push_back(GetSegment(5,PROBES_NO));
	
	for(int i = 10; i >= 0; i--){
		segments.push_back(GetSegment(i, PROBES_NO));
	}

	//Act
	ArticulationAmplitude::Module module(PROBES_NO);
	module.Calculate(segments);

	//Assert
	ASSERT_EQ(2, module.sounds.size());
	ASSERT_EQ(0, module.sounds[0].segment_id);
	ASSERT_EQ(12, module.sounds[1].segment_id);
}

#include <iostream>
TEST(articulationAmplitudeWavTest, ComparingTwoSameFiles){
	//Arange
    constexpr int PROBES_NO = 32;

	ArticulationAmplitude::Module mainModule(PROBES_NO);
    auto mainData = mainModule.ConvertWavToVector("../rsc/test3.wav");
    	
    ArticulationAmplitude::Module refModule(PROBES_NO);
    auto refData = refModule.ConvertWavToVector("../rsc/test3.wav");

	//Act
	mainModule.Calculate(mainData);
	refModule.Calculate(refData);

    auto value = ArticulationAmplitude::Module::CompareWithReference(mainModule.sounds, refModule.sounds);

	//Assert
	ASSERT_EQ(1, value);
}
