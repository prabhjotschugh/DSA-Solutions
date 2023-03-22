class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
      long cnt = 0, zeroSubarraysEndingAtCurrentIndex = 0;
        for (int n : nums) {
            if (n == 0) {
                cnt += ++zeroSubarraysEndingAtCurrentIndex;
            } else {
                zeroSubarraysEndingAtCurrentIndex = 0;
            }
        }
        return cnt;  
    }
};