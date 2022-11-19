#pragma once
#include "gtest/gtest.h"

#include "tmp.h"

TEST(TmpTest, getOneTest){
    ASSERT_EQ(getOne(), 1);
}

