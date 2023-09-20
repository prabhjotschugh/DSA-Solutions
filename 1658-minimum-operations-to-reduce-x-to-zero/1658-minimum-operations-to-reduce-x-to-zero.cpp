class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;
        int maxLength = -1, currSum = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            currSum += nums[r];
            while (l <= r && currSum > totalSum - x)
                currSum -= nums[l++];
            if (currSum == totalSum - x)
                maxLength = max(maxLength, r - l + 1);
        }
        return maxLength == -1 ? -1 : nums.size() - maxLength;
    }
};