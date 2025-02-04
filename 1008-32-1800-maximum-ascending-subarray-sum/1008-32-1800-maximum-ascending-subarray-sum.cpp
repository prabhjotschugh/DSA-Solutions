class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, 
        [&, sum=0, i=-1](int maxSum, int x) mutable{
            return maxSum=max(sum=(++i==0||x<=nums[i-1])?x:sum+x, maxSum);});
    }
};