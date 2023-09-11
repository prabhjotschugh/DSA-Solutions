class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        int n=groupSizes.size();
        for(int i=0; i<n; i++){
            int x=groupSizes[i];
            mp[x].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto& [x, v]: mp){
            int q=v.size()/x;
            for(int i=0; i<q; i++){
                vector<int> v_sz(x);
                copy(v.cbegin()+(i*x), v.cbegin()+((i+1)*x), v_sz.begin());
                ans.push_back(v_sz);
            }
        }
        return ans;
    }
};