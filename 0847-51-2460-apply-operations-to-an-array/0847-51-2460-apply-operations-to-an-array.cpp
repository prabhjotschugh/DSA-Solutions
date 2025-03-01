class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int n=nums.size();
        vector<int> ans(n, 0);
        int j=0;
        for(int i=0; i<n-1; i++){
            if (nums[i]==nums[i+1]){
                nums[i]<<=1;
                nums[i+1]=0;
            }
            if (nums[i]) ans[j++]=nums[i];
        }
        if (nums.back()) ans[j++]=nums.back();
        return ans;
    }
};