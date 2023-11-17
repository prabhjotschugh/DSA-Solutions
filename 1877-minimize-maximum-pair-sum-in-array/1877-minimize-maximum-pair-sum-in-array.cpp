class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int start=0;
        int end=n-1;
        int maxsum=INT_MIN;
        while(start<end)
        {
            int sum=nums[start]+nums[end];
            maxsum=(sum>maxsum)?sum:maxsum;
            start++;
            end--;
        }
        return maxsum;
    }
};