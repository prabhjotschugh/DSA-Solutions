class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0;
        int mx=0,count=0,total=0;
        while(r<nums.size()){
            if(nums[r]==0){
                count++;
                    while(count>1){
                        if(nums[l]==0)count--;
                        else total--;
                        l++;
                    }
            }
            else{
                total++;
                mx = max(mx,total);
            }
            r++;
        }
        if(mx==nums.size())mx--;
        return mx;
    }
};