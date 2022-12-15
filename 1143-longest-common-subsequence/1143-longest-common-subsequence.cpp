class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int dp[1001][1001] = {};
        for(int i=0; i<m ; i++){
            for(int j=0; j<n; j++){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                }
                else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[m][n];
    }
};