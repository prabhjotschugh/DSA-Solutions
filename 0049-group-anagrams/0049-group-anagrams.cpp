class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> ans;
        
        for(string s: strs){
            string key = s;
            sort(key.begin(), key.end());
            umap[key].push_back(s);
        }
        
        for(auto i:umap){
            ans.push_back(i.second);
        }
        return ans;
    }
};