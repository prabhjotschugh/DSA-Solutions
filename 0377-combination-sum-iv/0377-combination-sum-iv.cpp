class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return 0;
        vector<unsigned long long> dp(target+1, 0);
        
        dp[0] = 1;
        for(int tar=1;tar<=target;tar++){
            for(auto ele : nums){
                if(tar >= ele){
                    dp[tar] += dp[tar - ele];
                }
            }
        }
        return (int) dp[target];
    }
};