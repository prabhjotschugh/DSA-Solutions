class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=nums[i];
            if( val  > 0 && val <= n){
            int box=val-1;
                if(val != nums[box]){
                    swap(nums[box],nums[i]);
                    i--;
                }
            }
        }
        for(int i=0;i<n;i++)
            if(i+1!=nums[i]) return i+1;
        
        return n+1;
    }
};