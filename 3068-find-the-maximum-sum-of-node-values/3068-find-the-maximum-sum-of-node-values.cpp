class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> diff(n);
        long sum = 0;

        for (int i = 0; i < n; ++i) {
            diff[i] = (nums[i] ^ k) - nums[i];
            sum += nums[i];
        }
        sort(diff.begin(), diff.end(), std::greater<int>());
        for (int i = 0; i < n; i += 2) {
            if (i + 1 == n) return sum;
            int pair = diff[i] + diff[i + 1];
            if (pair > 0) sum += pair;
        }
        return sum;
    }
};