#include "gmock/gmock.h"
#include "stringmatching.cpp"
#include <string>
#include <iostream>
using std::cout;
using std::string;

using namespace testing;

class StirngMatchingFixture : public Test {
public:
    void checkMatchingLengthScore(int expectedScore, CompareStirng compareStr) {
        StringMatching strMatching;
        EXPECT_EQ(expectedScore, strMatching.getScore(compareStr));
    }
private:
};

TEST_F(StirngMatchingFixture, SameLength) {
    CompareStirng compareStr = {"ASD","DSA"};
    checkMatchingLengthScore(MAX_SCORE_FOR_STR_LEGNTH, compareStr);
}

TEST_F(StirngMatchingFixture, strAlong) {
    CompareStirng compareStr = { "ASDD","DSA" };
    checkMatchingLengthScore(45, compareStr);
}

TEST_F(StirngMatchingFixture, strAlongX2) {
    CompareStirng compareStr = { "AA","B" };
    checkMatchingLengthScore(0, compareStr);
}

TEST_F(StirngMatchingFixture, strBlong) {
    CompareStirng compareStr = { "ASD","DSAD" };
    checkMatchingLengthScore(45, compareStr);
}
TEST_F(StirngMatchingFixture, strBlongX2) {
    CompareStirng compareStr = { "BB","CCCC" };
    checkMatchingLengthScore(0, compareStr);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}