class Solution {
public:
    bool subsetSum(vector<int> &nums, int target) {
        int n = nums.size();
        bool dp[n+1][target+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=target; j++) {
                if(i==0)    
                    dp[i][j]=false;
                else if(j==0)
                    dp[i][j]=true;
            }
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=target; j++) {
                if(nums[i-1] <= j)
                    dp[i][j] = (dp[i-1][j-nums[i-1]]) || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        
        int sum = 0;
        for(auto ele:nums){
            sum += ele;
        }
        
        if(sum%2 != 0){
            return 0;
        }
        
        int target = sum/2;
        return subsetSum(nums, target);
    }
};