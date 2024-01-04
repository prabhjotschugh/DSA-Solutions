class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        int ans = 0;
        for (auto& kv : mp) {
            int i = kv.second;
            if (i == 1) {
                return -1;
            }
            ans += (i+2) / 3;
        }
        return ans;
    }
};