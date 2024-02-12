class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(auto i:nums){
            umap[i]++;
        }
        
        for(auto pair: umap){
            if(pair.second > (nums.size()/2)){
                return pair.first;
            }
        }
        return -1;
    }
};