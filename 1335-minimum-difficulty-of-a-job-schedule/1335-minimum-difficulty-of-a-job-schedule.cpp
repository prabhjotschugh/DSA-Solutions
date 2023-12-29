class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if (n<d) return -1;
        int dp[302][2];
        memset(dp, 1e6, sizeof(dp));
        dp[n][0]=0;
        for (int sub=1; sub <= d; sub++) {
             for (int i = n-sub; i >= 0; i--){
                int sum = 1e6, next = 0;

                for (int j= i; j <= n-sub; j++) {
                    next = max(next, jobDifficulty[j]);
                    sum = min(sum, next+dp[j+1][(sub-1)&1]);  
                }

                dp[i][sub&1] = sum;
            }
        }

        return dp[0][d&1]>=1e6 ?-1:dp[0][d&1];
    }
};