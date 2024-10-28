class Solution {
public:
    void getSequence(vector<int>&nums,long long start,int &temp_long,vector<bool>&vis){
        start=start*start;
        while(1){
            auto it = lower_bound(nums.begin(),nums.end(),start);
            if(it!=nums.end() && start==(*it)){
                start*=start;vis[it-nums.begin()]=1;
                temp_long++;
            }
            else break;
        }
    }
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        vector<bool>vis(n,0);
        int longest = 0 ,temp_long=0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                temp_long=1;
                getSequence(nums,nums[i],temp_long,vis);
                longest=max(longest,temp_long);
            }
        }
        if(longest<2)return -1;
        return longest;
    }
};