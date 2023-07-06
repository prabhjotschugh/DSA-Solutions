class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0, j=0, sum=0, mini=n+1;
		
        while(j<n){
            sum+=nums[j]; 
            while(i<=j && sum>=target){
                mini = min(mini,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (mini == n+1 ? 0 : mini);
    }
};