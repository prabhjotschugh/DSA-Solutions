class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        long long int sum = 0;
        int ans = 0;
        umap[0] = 1;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            sum = (sum%k + k ) % k;
            
            if(umap.find(sum) != umap.end()){
                ans += umap[sum];
            }
            umap[sum]++;
        }
        return ans;
    }
};