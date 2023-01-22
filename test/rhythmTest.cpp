#pragma once
#include "gtest/gtest.h"

#include "RhythmModule.hpp"
#include "OnsetDetectionFunction.hpp"
#include <iostream>


TEST(rhythmTest, ODFTest1){
	size_t frameProbesNo = 1024, hopProbesNo = 512;
	double data[512] = { 1 };
	auto odf = OnsetDetectionFunction(frameProbesNo, hopProbesNo);
	double returnedValue = odf.calculateDF(data);
	ASSERT_EQ(returnedValue, 1);
}

TEST(rhythmTest, ODFTest2){
	size_t frameProbesNo = 1024, hopProbesNo = 512;
        double data[512] = { 2.0 };
	auto odf = OnsetDetectionFunction(frameProbesNo, hopProbesNo);
        double returnedValue = odf.calculateDF(data);
        ASSERT_EQ(returnedValue, 4.0);
	data[0] = 1.1;
	returnedValue = odf.calculateDF(data);
	ASSERT_EQ(returnedValue, 1.21);
	data[0] = 0.0;
        returnedValue = odf.calculateDF(data);
        ASSERT_EQ(returnedValue, 0);
}

TEST(rhythmTest, CumulativeScoreTest){
        size_t frameProbesNo = 1024, hopProbesNo = 512;
        double data[512] = { 1 };
	auto rhythmModule = RhythmModule(frameProbesNo, hopProbesNo);
	rhythmModule.processFrame(data);
	double lastScore = rhythmModule.getLastCumulativeScore();
	std::cout << "abc: " << lastScore << "\n";
	ASSERT_EQ(lastScore, 0.1);

}






