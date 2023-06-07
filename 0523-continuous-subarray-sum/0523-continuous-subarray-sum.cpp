class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        long long int sum = 0;
        int maxi = 0;
        umap[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            sum = (sum%k + k) %k;
                
            if(umap.find(sum) != umap.end()){
                maxi = max(maxi, i-umap[sum]);
                if(maxi >= 2) return true;
            }else{
                umap[sum] = i;
            }
        }
        
        return false;
    }
};