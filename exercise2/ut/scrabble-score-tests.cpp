#include "gtest/gtest.h"
#include "scrabble-score.hpp"

struct ScrabbleTestSuite {};

TEST(ScrabbleTestSuite, dummyTest)
{
    ASSERT_TRUE(true);
}

TEST(ScrabbleTestSuite, DUPA)
{
    ASSERT_EQ(scrabbleScore("DUPA"), 7);
}

TEST(ScrabbleTestSuite, EmptyWord)
{
    ASSERT_EQ(scrabbleScore(""), 0);
}

TEST(ScrabbleTestSuite, smallLettersIna)
{
    ASSERT_EQ(scrabbleScore("ina"), 3);
}

TEST(ScrabbleTestSuite, theMissleTest)
{
    ASSERT_EQ(scrabbleScore("the missile knows where it is at all times\
        It knows this because it knows where it isnt by subtracting where it is\
        from where it isnt or where it isnt from where it is whichever\
        is greater it obtains a difference or deviation"), 303);
}

TEST(ScrabbleTestSuite, dog)
{
    ASSERT_EQ(scrabbleScore("dog"), 5);
}

TEST(ScrabbleTestSuite, CharakterA)
{
    ASSERT_EQ(scrabbleScore("A"), 1);
}