class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0) return {};
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1); 
        vector<int> prev_index(nums.size(), -1); 
        int maxi = 0; 
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev_index[i] = j;
                    if (dp[i] > dp[maxi]) {
                        maxi = i;  
                    }
                }
            }
        }
        vector<int> result;
        while (maxi >= 0) {
            result.push_back(nums[maxi]);
            maxi = prev_index[maxi];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};