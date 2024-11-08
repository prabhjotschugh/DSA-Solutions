class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> result;
        int xoor = 0;
        for(auto&num: nums) xoor ^= num;
        int mask = pow(2,maximumBit) - 1; 
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            result.push_back(xoor ^ mask);
            xoor ^= nums[i];
        }
        return result;
    }
};