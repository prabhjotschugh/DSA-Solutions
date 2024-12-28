class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int K) {
        int n = nums.size();
        vector<int> presum(n+1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i-1] + nums[i-1];
        }
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(4, vector<int>(2, 0)));
        int mx = 0, pos = -1;
        for (int k = 1; k <= 3; k++) {
            for (int i = K; i <= n; i++) {
                dp[i][k][0] = dp[i-1][k][0];
                dp[i][k][1] = dp[i-1][k][1];
                int sumk = presum[i] - presum[i-K];
                if (dp[i][k][0]  < dp[i-K][k-1][0] + sumk) {             
                    dp[i][k][0] = dp[i-K][k-1][0] + sumk;
                    dp[i][k][1] = i;
                }
                if (dp[i][k][0] > mx) {
                    mx = dp[i][k][0];
                    pos = dp[i][k][1];
                }
            }
        }
        vector<int> result;
        for (int i = 3; i > 0; i--) {
            result.push_back(pos-K);
            pos = dp[pos-K][i-1][1];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};