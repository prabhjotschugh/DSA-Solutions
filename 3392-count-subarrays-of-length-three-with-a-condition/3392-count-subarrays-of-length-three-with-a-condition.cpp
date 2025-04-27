class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        return count_if(nums.begin(), nums.end(),
        [&,i=-1](int x) mutable{
            return (++i==0 || i==nums.size()-1)?0:2*(nums[i-1]+nums[i+1])==x;
        });
    }
};