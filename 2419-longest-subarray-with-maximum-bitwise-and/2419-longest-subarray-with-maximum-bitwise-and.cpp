class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int temp_length=0;
        int ans=1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi) temp_length++;
            else temp_length=0;
            ans=max(ans,temp_length);
        }
        return ans;
    }
};