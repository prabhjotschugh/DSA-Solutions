class Solution {
public:
    int countSubstrings(string str) {
        int n = str.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int  counter=0;
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap ; i<n,j<n ; i++,j++){
                if(gap == 0){
                    dp[i][j] = 1;
                }
                else if(gap == 1 && str[i] == str[j]){
                    dp[i][j] = 2;
                }
                else if(str[i] == str[j] && dp[i+1][j-1] > 0){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                
                if(dp[i][j] == true){
                    counter++;
                }
            }
        }
        return counter;
    }
};