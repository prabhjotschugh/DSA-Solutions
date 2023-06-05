class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        vector<int> ans;
        for(auto i: nums1){
            umap[i]++;
        }
        for(auto i: nums2){
            if(umap[i] > 0){
                umap[i] = 0;
                ans.push_back(i);
            }
        }
        return ans;
    }
};