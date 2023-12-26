class Solution {
public:
    const int mod = 1000000007;

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, std::vector<int>(target + 1, -1));
        return helper(n, k, target, dp);
    }

    int helper(int n, int k, int target, vector<vector<int>>& dp) {
        if (n == 0 && target == 0) return 1;
        if (n == 0 || target <= 0) return 0;
        if (dp[n][target] != -1) return dp[n][target] % mod;
        dp[n][target] = 0;

        for (int i = 1; i <= k; i++) {
            dp[n][target] = (dp[n][target] + helper(n - 1, k, target - i, dp)) % mod;
        }

        return dp[n][target];
    }
};