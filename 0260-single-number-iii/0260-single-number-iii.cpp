class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(auto i: nums){
            umap[i]++;
        }
        
        vector<int> ans;
        for(auto i: umap){
            if(i.second == 1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};