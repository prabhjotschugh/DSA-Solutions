class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = accumulate(nums.begin(), nums.end(), 0, [](int a, int b) { return a | b; });
        return dfs(nums, 0, 0, maxOr);
    }
private:
    int dfs(vector<int>& nums, int i, int orVal, int maxOr) {
        return i == nums.size() ? (orVal == maxOr) : dfs(nums, i + 1, orVal | nums[i], maxOr) + dfs(nums, i + 1, orVal, maxOr);
    }
};