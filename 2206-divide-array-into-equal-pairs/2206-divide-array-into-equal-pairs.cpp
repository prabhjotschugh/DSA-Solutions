class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501, 0);
        for (int num : nums) {
            freq[num]++;
        }
        for (int count : freq) {
            if (count % 2 != 0) return false;
        }
        return true;
    }
};