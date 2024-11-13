class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 1; i++) {
            size_t low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            size_t up = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            ans += (up - low);
        }
        return ans;
    }
};