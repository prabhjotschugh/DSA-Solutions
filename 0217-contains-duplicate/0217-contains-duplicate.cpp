class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(auto i: nums){
            umap[i]++;
        }
        
        bool ans = false;
        for(auto i: umap){
            if(i.second >= 2){
                ans = true;
            }
        }
        return ans;
    }
};