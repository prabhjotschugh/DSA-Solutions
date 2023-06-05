class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        unordered_map<int, int> umap;
        int mini = 10000;
        for(int i=0;i<arr.size();i++){
            if(umap.find(arr[i]) != umap.end()){
                mini = min(mini, i-umap[arr[i]]);
                if(mini <= k){
                    return true;
                }
            }
            umap[arr[i]] = i;
        }
        return false;
    }
};