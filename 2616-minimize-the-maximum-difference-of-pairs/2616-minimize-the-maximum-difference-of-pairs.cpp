class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[n-1]-nums[0];
        int i=0,j=ans;
        while(i<=j){
           int m = (i+j)/2;
           int total = 0;
           int k = 0;
           while(k<n-1){
               if(nums[k+1]-nums[k]<=m){
                   total++;
                   k+=2;
               }
               else k++;
           }
           if(total>=p){
               ans = m;
               j = m-1;
           }
           else i = m+1;
        }
        return ans;
    }
};