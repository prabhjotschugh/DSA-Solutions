class Solution {
public:
    bool canJump(vector<int>& nums) {
                int n = 0;
                if(nums.size() == 1)    return true;
                if(nums[0] == 0)    return false;
                for(int i = 0; i<nums.size(); i++){
                    if(n >= nums.size()-1)  return true;
                    if(n == i && nums[i] == 0)  return false;
                    n = max(nums[i]+i, n);
                }
                return false;
        
    }
};