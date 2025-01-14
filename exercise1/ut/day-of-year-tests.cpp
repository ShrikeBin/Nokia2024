#include "gtest/gtest.h"
#include "day-of-year.hpp"

struct DayOfYearTestSuite {};

TEST(DayOfYearTestSuite, dummyTest)
{
  ASSERT_TRUE(true);
}

TEST(DayOfYearTestSuite, January1stIsFitstDayOfYear)
{
  ASSERT_EQ(dayOfYear(1, 1, 2020), 1);
}

TEST(DayOfYearTestSuite, March1stIs61DayOfLeapYear)
{
  ASSERT_EQ(dayOfYear(3, 1, 2020), 61);
}

TEST(DayOfYearTestSuite, March1stIs60DayOfYear)
{
  ASSERT_EQ(dayOfYear(3, 1, 2019), 60);
}

TEST(DayOfYearTestSuite, Leap2000)
{
  ASSERT_EQ(dayOfYear(3, 1, 2000), 61);
}

TEST(DayOfYearTestSuite, NonLeap1900)
{
  ASSERT_EQ(dayOfYear(3, 1, 1900), 60);
}
