#include "gmock/gmock.h"
#include "stringmatching.cpp"
#include <string>
#include <iostream>
using std::cout;
using std::string;

using namespace testing;

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}