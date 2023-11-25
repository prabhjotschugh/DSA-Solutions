class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int total_sum=0;
        int n=nums.size();
        for(int i=0; i<n; i++)total_sum+=nums[i];
        vector<int> ans;
        int curr_sum=0;
        for(int i=0; i<n; i++){
            curr_sum+=nums[i];
            int Rsum=total_sum-curr_sum;
            int Lsum=curr_sum-nums[i];
            Lsum=(i*nums[i])-Lsum;
            Rsum=Rsum-(n-(i+1))*nums[i];
            ans.push_back(Lsum+Rsum);
        }
        return ans;
    }
};