class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        int n = nums.size();
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        
        for (int i = 1; i < n; i++) {
            maxEndingHere = std::max(nums[i], maxEndingHere + nums[i]);
            minEndingHere = std::min(nums[i], minEndingHere + nums[i]);
            maxSoFar = std::max(maxSoFar, maxEndingHere);
            minSoFar = std::min(minSoFar, minEndingHere);
        }
        
        return std::max(std::abs(maxSoFar), std::abs(minSoFar));
    }
};