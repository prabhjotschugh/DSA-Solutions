class Solution {
public:
    int countSubstrings(string str) {
        int n = str.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int  counter=0;
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap ; i<n,j<n ; i++,j++){
                if(gap==0){
                    dp[i][j] = true;   //diagonal
                }
                else if(gap == 1){
                    dp[i][j] = str[i] == str[j];
                }
                else{
                    dp[i][j] = (str[i] == str[j] && dp[i+1][j-1]);
                }
                
                if(dp[i][j] == true){
                    counter++;
                }
            }
        }
        return counter;
    }
};