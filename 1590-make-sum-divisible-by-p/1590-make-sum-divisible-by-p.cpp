#define ll long long
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        ll total = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = total % p;
        if(rem == 0) return 0;

        unordered_map<int,int> mp;
        int presum = 0;
        mp[0] = -1;
        int minlen = n;

        for(int i=0; i<n; i++){
            presum = (presum + nums[i]) % p;
            int t = (presum - rem + p) % p;
            if(mp.find(t) != mp.end()) minlen = min(minlen, i-mp[t]);
            mp[presum] = i; 
        }

        return minlen == n ? -1 : minlen;
    }
};