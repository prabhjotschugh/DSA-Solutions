class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int res =0,diff =INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n-1;i++){
            int l = i+1;
            int r = n -1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(abs(target-sum)<diff){
                    diff = abs(target-sum);
                    res = sum;
                }
                if(sum == target){ 
                    return target;
                }
                if(sum<target){
                    l++;
                }
                else r--;
            } 
        }
        return res;
    }
};