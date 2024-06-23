class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int, greater<int>> ms;
        int longest = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            ms.insert(nums[r]);
            int largest = *ms.begin();
            int smallest = *ms.rbegin();
            while (abs(largest - smallest) > limit) {
                ms.erase(ms.find(nums[l]));

                l++;
                largest = *ms.begin();
                smallest = *ms.rbegin();
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};