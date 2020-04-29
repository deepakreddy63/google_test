#include <limits.h>
#include "hello.h"
#include "gtest/gtest.h"
namespace {   //anonymous
  TEST(LeapYearTest, InvalidInputs) {
    EXPECT_EQ(-1, IsLeapYear(-1500));
    EXPECT_EQ(-1, IsLeapYear(-1996));
    EXPECT_TRUE(-1==IsLeapYear(-1000));
  }
  TEST(LeapYearTest, LeapYears) {
    EXPECT_EQ(1, IsLeapYear(1996));
    EXPECT_EQ(1, IsLeapYear(2400));
    EXPECT_TRUE(1==IsLeapYear(2016));
  }
  TEST(LeapYearTest, NonLeapYears) {
    EXPECT_EQ(0, IsLeapYear(2018));
    EXPECT_EQ(0, IsLeapYear(1995));
    EXPECT_NE(1, IsLeapYear(1900));
    EXPECT_FALSE(1==IsLeapYear(2100));
  }
}