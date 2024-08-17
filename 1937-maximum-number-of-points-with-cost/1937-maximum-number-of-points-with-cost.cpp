class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long> dp(n, 0);
        long ans = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[j] += points[i][j];
            }
            
            for (int j = 1; j < n; ++j) {
                dp[j] = max(dp[j], dp[j - 1] - 1);
            }
            
            for (int j = n - 2; j >= 0; --j) {
                dp[j] = max(dp[j], dp[j + 1] - 1);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};