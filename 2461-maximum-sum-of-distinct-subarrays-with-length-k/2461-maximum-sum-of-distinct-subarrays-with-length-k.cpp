class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       long long n = nums.size(), ws = 0, mx = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            ws += nums[i];

            if (i >= k) {
                int le = nums[i - k];
                mp[le]--;
                ws -= le;
                if (mp[le] == 0) {
                    mp.erase(le);
                }
            }

            if (i >= k - 1 && mp.size() == k) {
                mx = max(mx, ws);
            }
        }

        return mx; 
    }
};