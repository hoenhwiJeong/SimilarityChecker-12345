#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SCORE_FOR_STR_LEGNTH = 60;

class CompareStirng {
public:
    string strA;
    string strB;
};

class StringMatching {
public:
    int getScore(const CompareStirng & compareStr) {
        int ret = 0;
        int maxStrLength = max(compareStr.strA.length(), compareStr.strB.length());
        int minStrLength = min(compareStr.strA.length(), compareStr.strB.length());

        if (isSameLength(maxStrLength, minStrLength))
            return MAX_SCORE_FOR_STR_LEGNTH;

        if (isDoubleLength(maxStrLength, minStrLength))
            return ret;

        ret = getLengthScore(maxStrLength, minStrLength);

        return ret;
    }
private:
    int getLengthScore(int maxStrLength, int minStrLength)
    {
        double gapRatio = static_cast<double>(maxStrLength - minStrLength) / maxStrLength;
        return static_cast<int>((1.0 - gapRatio) * MAX_SCORE_FOR_STR_LEGNTH);
    }
    bool isDoubleLength(int maxStrLength, int minStrLength)
    {
        return maxStrLength >= minStrLength * 2;
    }
    bool isSameLength(int maxStrLength, int minStrLength)
    {
        return maxStrLength == minStrLength;
    }
};