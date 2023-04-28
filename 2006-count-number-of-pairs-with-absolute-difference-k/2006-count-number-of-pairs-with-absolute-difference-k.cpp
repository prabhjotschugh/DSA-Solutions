class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int num1 = nums[i]-k;
            int num2 = nums[i]+k;
            ans+=umap[num1];
            ans+=umap[num2];
            umap[nums[i]]++;
        }
        return ans;
    }
};