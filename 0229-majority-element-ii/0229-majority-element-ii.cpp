class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(), n_3=n/3;
        unordered_set<int> ans;
        unordered_map<int, int> mp;
        for(int x : nums){
            if (mp.count(x)==0) mp[x]=1;
            else mp[x]++;
            if (mp[x]>n_3) ans.insert(x);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};