class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int dp[arr.size()][arr.size()];
        int m[arr.size()][arr.size()];
        memset(m,0,sizeof(m));
        for(int g = 0;g<arr.size();g++){
            for(int i=0,j=g;j<arr.size();i++,j++){
                if(g==0){
                    m[i][j] = arr[i];
                }else{
                    m[i][j] = max(m[i][j-1],m[i+1][j]);
                }
            }
        }
        memset(dp,0,sizeof(dp));
        for(int g = 0;g<arr.size();g++){
            for(int i=0,j=g;j<arr.size();i++,j++){
                if(g==0){
                    dp[i][j] = 0;
                }else if(g == 1){
                    dp[i][j] = arr[i]*arr[j];
                }else{
                    int ans = INT_MAX;
                    for(int k = i;k < j;k++){
                         ans = min(ans,dp[i][k] + (m[i][k]*m[k+1][j]) + dp[k+1][j]);
                    }
                    dp[i][j] = ans;
                }
            }
        }
        return dp[0][arr.size()-1];
    }
};