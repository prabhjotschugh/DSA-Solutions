class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int count = startTime.size();
        vector<int> prefixSum(count + 1, 0);
        int maxFree = 0;

        for (int i = 0; i < count; ++i) {
            prefixSum[i + 1] = prefixSum[i] + (endTime[i] - startTime[i]);
        }

        for (int i = k - 1; i < count; ++i) {
            int occupied = prefixSum[i + 1] - prefixSum[i - k + 1];
            int windowEnd = (i == count - 1) ? eventTime : startTime[i + 1];
            int windowStart = (i == k - 1) ? 0 : endTime[i - k];
            int freeTime = windowEnd - windowStart - occupied;
            maxFree = max(maxFree, freeTime);
        }

        return maxFree;
    }
};