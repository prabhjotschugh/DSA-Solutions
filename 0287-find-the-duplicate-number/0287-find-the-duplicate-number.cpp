class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(auto i: nums){
            umap[i]++;
        }
        
        for(auto i: umap){
            if(i.second > 1){
                return i.first;
            }
        }
        return -1;
    }
};