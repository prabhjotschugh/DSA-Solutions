class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0, j=0, len=0, zero=0;
        int n=nums.size();
        
        while(j < n){
            if(nums[j++] == 0){
                zero++;
            }
            
            while(zero > 0){
                if(nums[i++] == 0){
                    zero--;
                }
            }
            len = max(len, j-i);
        }
        return len;
    }
};