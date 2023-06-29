class Solution {
public:
    int answer(int i, int j, string&s, vector<vector<int>>&dp){
        int n = s.length();
        
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j] != 0) {
            return dp[i][j];
        }
        
        if(s[i] == s[j]){
            return dp[i][j] = 2 + answer(i+1, j-1, s, dp);
        }else{
            return dp[i][j] = max(answer(i+1, j, s, dp) , answer(i, j-1, s, dp));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return answer(0, n-1, s, dp); 
    }
};