class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        int j=nums.size()-1;
        
        while(i<=j){
            if(abs(nums[i]) >= abs(nums[j])){
                ans.push_back(nums[i]*nums[i]);
                i++;
            }else if(abs(nums[i]) < abs(nums[j])){
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};