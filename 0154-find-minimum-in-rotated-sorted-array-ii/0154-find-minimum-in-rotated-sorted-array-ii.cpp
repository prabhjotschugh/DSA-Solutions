class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ; 
        int r = n-1;
        int ans;
        if(n==1) return nums[0];
        if(n==2) return min(nums[0],nums[1]);
        ans = nums[0];
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==nums[l] && nums[mid]==nums[r]){
                ans = min(ans,nums[mid]);
                l++;
                r--;
                continue;
            }
            if(nums[mid]>=nums[l]){
                ans = min(ans,nums[l]);
                l = mid+1;
            }else{
                ans = min(ans,nums[mid]);
                r = mid-1;
            }
        }
        return ans ;
    }
};