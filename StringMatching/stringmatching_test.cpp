#include "gmock/gmock.h"
#include "stringmatching.cpp"
#include <string>
#include <iostream>
using std::cout;
using std::string;

using namespace testing;

class StringMatchingFixture : public Test {
public:
    void checkMatchingLengthScore(int expectedScore, CompareStirng compareStr) {
        StringMatching strMatching;
        EXPECT_EQ(expectedScore, strMatching.getLengthScore(compareStr));
    }

    void checkMatchingUsedAlphabetScore(int expectedScore, CompareStirng compareStr) {
        StringMatching strMatching;
        EXPECT_EQ(expectedScore, strMatching.getUsedAlphabetScore(compareStr));
    }
private:
};

TEST_F(StringMatchingFixture, SameLength) {
    CompareStirng compareStr = {"ASD","DSA"};
    checkMatchingLengthScore(MAX_SCORE_FOR_STR_LEGNTH, compareStr);
}

TEST_F(StringMatchingFixture, strAlong) {
    CompareStirng compareStr = { "ASDD","DSA" };
    checkMatchingLengthScore(45, compareStr);
}

TEST_F(StringMatchingFixture, strAlongX2) {
    CompareStirng compareStr = { "AA","B" };
    checkMatchingLengthScore(0, compareStr);
}

TEST_F(StringMatchingFixture, strBlong) {
    CompareStirng compareStr = { "ASD","DSAD" };
    checkMatchingLengthScore(45, compareStr);
}
TEST_F(StringMatchingFixture, strBlongX2) {
    CompareStirng compareStr = { "BB","CCCC" };
    checkMatchingLengthScore(0, compareStr);
}

TEST_F(StringMatchingFixture, sameAlphabetUsed1) {
    CompareStirng compareStr = { "ABC","CAB" };
    checkMatchingUsedAlphabetScore(MAX_SCORE_FOR_STR_USED_ALPHABET, compareStr);
}

TEST_F(StringMatchingFixture, sameAlphabetUsed2) {
    CompareStirng compareStr = { "ABCDEF","FEDCAB" };
    checkMatchingUsedAlphabetScore(MAX_SCORE_FOR_STR_USED_ALPHABET, compareStr);
}

TEST_F(StringMatchingFixture, notsameAlphabetUsed1) {
    CompareStirng compareStr = { "ABCD","EFGH" };
    checkMatchingUsedAlphabetScore(0, compareStr);
}

TEST_F(StringMatchingFixture, notsameAlphabetUsed2) {
    CompareStirng compareStr = { "ABCDEFG","IKG" };
    checkMatchingUsedAlphabetScore(0, compareStr);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}