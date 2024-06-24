class Solution {
public:
    int minKBitFlips(vector<int>& nums, int K) {
        int n = nums.size(), flipped = 0, res = 0;
        vector<int> isFlipped(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (i >= K)
                flipped ^= isFlipped[i - K];
            if (flipped == nums[i]) {
                if (i + K > n)
                    return -1;
                isFlipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }
        return res;
    }
};