class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int op = 0, r = n - 1;
        while (r >= 0) {
            while ((r > 0) && (nums[r - 1] == nums[r])) r--;
            r--;
            if (r >= 0) op += (n - r - 1);
        }
        return op;
    }
};