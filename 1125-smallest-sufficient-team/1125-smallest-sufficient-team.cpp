class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& r, vector<vector<string>>& p) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n = r.size();
        unordered_map<int, vector<int>> ans;
        ans[0] = {};

        unordered_map<string, int> mp;
        for(int i = 0;i < r.size();i++)
            mp[r[i]] = i;
        
        for(int i = 0;i < p.size();i++){
            int cur = 0;
            for(auto s : p[i])
                cur |= 1 << mp[s];

            unordered_map<int, vector<int>> temp = ans;
            for(auto &[mask, vec] : ans){
                int comb = mask | cur;
                if(temp.find(comb) == temp.end() || temp[comb].size() > 1 + vec.size()){
                    temp[comb] = vec;
                    temp[comb].push_back(i);
                } 
            }
            ans = temp; 
        }
        return ans[(1 << n) - 1];
    }
};