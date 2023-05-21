class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> umap;
        int sum=0, counter=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(sum==k){
                counter++;
            }
            
            if(umap.find(sum-k) != umap.end()){
                counter+=umap[sum-k];
            }
            
            umap[sum]++;
        }
        return counter;
    }
};