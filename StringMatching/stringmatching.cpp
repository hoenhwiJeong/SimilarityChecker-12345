#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SCORE_FOR_STR_LEGNTH = 60;
const int MAX_SCORE_FOR_STR_USED_ALPHABET = 40;

class CompareStirng {
public:
    string strA;
    string strB;
};

class StringMatching {
public:
    int getLengthScore(const CompareStirng & compareStr) {
        int ret = 0;
        int maxStrLength = max(compareStr.strA.length(), compareStr.strB.length());
        int minStrLength = min(compareStr.strA.length(), compareStr.strB.length());

        if (isSameLength(maxStrLength, minStrLength))
            return MAX_SCORE_FOR_STR_LEGNTH;

        if (isDoubleLength(maxStrLength, minStrLength))
            return ret;

        ret = getLengthScoreCalcualor(maxStrLength, minStrLength);

        return ret;
    }

    int getUsedAlphabetScore(const CompareStirng& compareStr) {
        int ret = 0;
        int countStrA = 0;
        int countStrB = 0;
        for (int i = 0; i < compareStr.strA.size(); i++) {
            for (int j = 0; j < compareStr.strB.size(); j++) {
                if (compareStr.strA[i] == compareStr.strB[j]) {
                    countStrA++;
                    break;
                }

            }
        }
        for (int i = 0; i < compareStr.strB.size(); i++) {
            for (int j = 0; j < compareStr.strA.size(); j++) {
                if (compareStr.strA[i] == compareStr.strB[j]) {
                    countStrB++;
                    break;
                }

            }
        }

        if (countStrA == compareStr.strA.size() && countStrB == compareStr.strB.size())
            return MAX_SCORE_FOR_STR_USED_ALPHABET;

        return ret;
    }
private:
    int getLengthScoreCalcualor(int maxStrLength, int minStrLength)
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