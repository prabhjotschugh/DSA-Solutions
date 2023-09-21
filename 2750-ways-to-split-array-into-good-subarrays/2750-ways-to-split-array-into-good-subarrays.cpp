class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int mod=1e9+7;
        int n=nums.size();
        long long cnt=0, cnt1=0;
        long long ways=1;

        int cnt0=0;
        for(auto i: nums) if(i==0) cnt0++;
        if(cnt0==n) return 0;

        for(int i=0; i<n; i++){
            if(nums[i]==1) cnt1++;
            if(cnt1==1) cnt++;

            if(cnt1>1){
                ways=(ways%mod*cnt)%mod;
                cnt=1;
                cnt1=1;
            }

        }
        return (ways)%mod;  
    }
};