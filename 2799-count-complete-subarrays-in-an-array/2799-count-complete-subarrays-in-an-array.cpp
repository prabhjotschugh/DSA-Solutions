class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> all(nums.begin(), nums.end());
        int totalDistinct = all.size(), count = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                seen.insert(nums[j]);
                if (seen.size() == totalDistinct) {
                    count += n - j;
                    break;
                }
            }
        }

        return count;
    }
};