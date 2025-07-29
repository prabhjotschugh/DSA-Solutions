class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> nearest(32, -1);
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {
                    nearest[j] = i;
                }
            }
            
            int lastSetBit = i;
            for (int j = 0; j < 32; j++) {
                lastSetBit = max(lastSetBit, nearest[j]);
            }

            ans[i] = lastSetBit - i + 1;
        }
        
        return ans;
    }
};