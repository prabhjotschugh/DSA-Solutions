class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;

        while(i < n) {
            mp[nums[i]]++;
            while(mp[nums[i]] > k) {
                mp[nums[j]]--;
                j++;
            }
            ans = max(ans, (i - j + 1));
            i++;
        }

        return ans;
    }
};