class Solution {
public:
    int knightDialer(int n) {
        long long prev[]={1,1,1,1,1,1};
        long long dp[]={1,1,1,1,1,1};
        int adj[3][2]={{4,4}, {4,2}, {3,1}};
        int mod=1000000007;
        while((n--))
        {
            for(int i=0; i<=2; i++)
                dp[i]=(prev[adj[i][0]]+prev[adj[i][1]])%mod;
            dp[3]=dp[1];
            dp[4]=dp[2]+prev[0];
            dp[5]=0;
            swap(prev, dp);
        }
        int sum{};
        for(int i=0; i<6; i++)
            sum=(sum+dp[i])%mod;
        for(int i=1; i<5; i++)
            sum=(sum+dp[i])%mod;
        return sum;
    }
};