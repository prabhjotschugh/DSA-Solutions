class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans=0,cur=0;
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            long long val=ceil((cur)/(i+1.0));
            ans=max(ans,val);
        }
        return ans;
    }
};