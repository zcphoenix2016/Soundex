#include "gtest/gtest.h"
#include "../Soundex.hpp"

using namespace testing;

struct Tests : public Test
{

};

TEST_F(Tests, testForAllVowel)
{
    ASSERT_EQ("p000", Soundex::encode("Paeiou"));
    ASSERT_EQ("p300", Soundex::encode("Phhhhht"));
}
TEST_F(Tests, testForMapLetterToNum)
{
    ASSERT_EQ("p234", Soundex::encode("Pcdl"));
}
TEST_F(Tests, testForOneVowelLetter)
{
    ASSERT_EQ("a000", Soundex::encode("a"));
}
TEST_F(Tests, testForOneVowelUpLetter)
{
    ASSERT_EQ("i000", Soundex::encode("IA"));
}

TEST_F(Tests, testForAlongString)
{
    ASSERT_EQ("p234", Soundex::encode("Pcdlcdl"));
}

TEST_F(Tests, testForRemoveTheSameNum)
{
    ASSERT_EQ("p240", Soundex::encode("Pcql"));
}

TEST_F(Tests, testForRemoveTheSameNumWithFirstLetter)
{
    ASSERT_EQ("p240", Soundex::encode("Pfql"));
}

TEST_F(Tests, testForRemovetheVowel)
{
    ASSERT_EQ("p400", Soundex::encode("Paaal"));
    ASSERT_EQ("p400", Soundex::encode("Pyl"));
}

TEST_F(Tests, testForSpecialLetter)
{
    ASSERT_EQ("p400", Soundex::encode("Phl"));
    ASSERT_EQ("p400", Soundex::encode("Pwl"));
}

TEST_F(Tests, testForSameNumAroundHorW)
{
    ASSERT_EQ("t100", Soundex::encode("tfhp"));
    ASSERT_EQ("p000", Soundex::encode("Php"));
}

TEST_F(Tests, testForSameNumAroundVowel)
{
    ASSERT_EQ("t110", Soundex::encode("tpap"));
    ASSERT_EQ("t111", Soundex::encode("tttpapap"));
}

TEST_F(Tests, testsForExcptions)
{
    ASSERT_THROW(Soundex::encode(""), invalid_argument);
    ASSERT_THROW(Soundex::encode("1#"), invalid_argument);
    ASSERT_THROW(Soundex::encode("#pay"), invalid_argument);
}

TEST_F(Tests, testForACs)
{
    ASSERT_EQ("r163", Soundex::encode("Robert"));
    ASSERT_EQ("r163", Soundex::encode("Rubert"));
    ASSERT_EQ("r150", Soundex::encode("Rubin"));
    ASSERT_EQ("a261",Soundex::encode("Ashcraft"));
    ASSERT_EQ("a261", Soundex::encode("Ashcroft"));
    ASSERT_EQ("t522", Soundex::encode("Tymczak"));
    ASSERT_EQ("p236", Soundex::encode("Pfister"));
}
