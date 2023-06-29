class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxi = 0,si = 0, ei = 0;
        for(int gap=0;gap<n;gap++){
            for(int i=0, j=gap ; i<n, j<n ; i++, j++){
                
                if(gap == 0){
                    dp[i][j] = 1;
                }
                else if(gap == 1 && s[i] == s[j]){
                    dp[i][j] = 2;
                }
                else if(s[i] == s[j] && dp[i+1][j-1] > 0){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                
                if(dp[i][j] > maxi){
                    maxi = dp[i][j];
                    si = i;
                    ei = j;
                }
            }
        }
        return s.substr(si, ei-si+1);
    }
};