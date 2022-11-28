class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
            int flag=0;
            int index=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=val){
                    nums[index] = nums[i];
                    index++;
                    flag=1;
                }
            }
            if(flag==0){
                return 0;
            }
            return index;
    }
};