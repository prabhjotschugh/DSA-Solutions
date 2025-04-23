class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> digitCountFreq;
        int maxDigitCount = 0, maxDigitFreq = 0;

        for (int i = 1; i <= n; i++) {
            int digitSum = 0, key = i;
            while (key > 0) {
                digitSum += key % 10;
                key /= 10;
            }
            digitCountFreq[digitSum]++;
            maxDigitCount = max(maxDigitCount, digitCountFreq[digitSum]);
        }

        for (auto digit : digitCountFreq) {
            if (digit.second == maxDigitCount) {
                maxDigitFreq++;
            }
        }
        return maxDigitFreq;
    }
};