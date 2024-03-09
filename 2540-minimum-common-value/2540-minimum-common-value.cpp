class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> umap;
        for(auto& i:nums1){
            umap[i]++;
        }
        
        for(auto& i:nums2){
            if(umap[i]){
                return i;
            }
        }
        return -1;
        
    }
};