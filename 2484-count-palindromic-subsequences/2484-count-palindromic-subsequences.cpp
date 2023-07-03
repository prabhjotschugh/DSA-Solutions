const int N = 1e4+4;
const int MOD = 1e9+7;
const int x = 5;
typedef long long ll;
ll dp[N][N];

class Solution {
public:
    int countPalindromes(string str) {
        ll ans = 0;
        memset(dp, sizeof(dp), 0);
        int n = str.size();
        for(int i = n-2; i>=0; i--){
            for(int j = i+2; j<n; j++){
                dp[i][j] = dp[i][j-1];
                if(str[i] == str[j]){
                    dp[i][j] = (dp[i][j] + j - i - 1)%MOD;
                }
                if(dp[i+1][j] != dp[i+1][j-1]){
                    dp[i][j] = (dp[i][j] - dp[i+1][j-1] + dp[i+1][j])%MOD;
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = i + x - 1; j<n; j++){
                if(str[i] == str[j]) ans = (ans + dp[i+1][j-1])%MOD;
            }
        }
        
        return ans;
    }
};