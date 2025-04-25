class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        const int n=nums.size();
        unordered_map<int, int> mp;
        mp[0]=1;
        mp.reserve(n);
        long long ans=0;
        int prefix=0;
        for(int i=0; i<n; i++){
            prefix+=((nums[i]%modulo)==k);
            ans+=mp[(prefix+modulo-k)%modulo];
            mp[prefix%modulo]++;
        }
        return ans;
    }
};