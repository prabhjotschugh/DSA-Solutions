class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        
        for(auto i:umap){
            if(i.second == 1){
                return i.first;
            }
        }
        return -1;
    }
};