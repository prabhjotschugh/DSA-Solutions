class Solution {
public:
    
    // Kadane's Algorithm
    
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=nums[0];
        for(auto i:nums){
            sum += i;
            maxi = max(maxi, sum);
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;
    }
};