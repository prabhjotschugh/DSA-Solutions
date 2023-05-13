class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[1000000] ={0};
        dp[0]=1;
        int ans=0;
        for(int i=1;i<=high;i++){
            dp[i] = ((i-zero>=0 ? dp[i-zero]:0)+(i-one>=0 ? dp[i-one]:0))%1000000007;
            if(i>=low){
                ans = (ans+dp[i])%1000000007;
            }
        }
        return ans;
    }
};