class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0;
        int j=0;
        int zeroCounter=0;
        int maxi=0;
        int n=nums.size();
        
        while(j<n){
            if(nums[j++] == 0){
                zeroCounter++;
            }
            
            while(zeroCounter > 0){
                if(nums[i++] == 0){
                    zeroCounter--;
                }
            }
            maxi = max(maxi, j-i);
        }
        return maxi;
    }
};