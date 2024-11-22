class Solution {
public:
    string f(auto& v) {
        string r;
        for (auto x : v)
            r += (x == v[0]);
        return r;
    }
    
    int maxEqualRowsAfterFlips(vector<vector<int>>& m) {
        map<string, int> mp; int mx = 0;
        for (auto& i : m)  mx = max(mx, ++mp[f(i)]);
        return mx;
    }
};