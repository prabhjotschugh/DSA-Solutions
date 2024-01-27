class Solution {
    public:
    int dp[1001][1001], mod = 1e9 + 7;
    long long dfs(int n, int k){
        if(n == 0) return 0;
        if(k == 0) return 1;
        if(dp[n][k] != -1) return dp[n][k];
        long long last = min(k, n-1), ans = 0;
        // f(n,k)=f(n−1,k)+f(n−1,k−1)+f(n−1,k−2)+⋯+f(n−1,k−n+1)
        for(int i = 0;i <= last;i++)
            ans = (ans + dfs(n-1, k-i))%mod;
        return dp[n][k] = ans%mod;
    }
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(n, k) % mod;
    }
};