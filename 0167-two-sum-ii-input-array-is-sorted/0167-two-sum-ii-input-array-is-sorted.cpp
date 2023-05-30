class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        for(int i=0;i<nums.size();i++){
            while(i<=j){
                 if(nums[i] + nums[j] == target){
                    return {i+1, j+1};
                }
                else if(nums[i] + nums[j] > target){
                    j--;
                }
                else{
                    i++;
                }  
            }
        }
        return vector<int> ();
    }
};