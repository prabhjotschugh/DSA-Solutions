class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr1 = -1;
        int index = 0;
        int n = nums.size();
        int ptr2 = n-1;
        if(n==0){
            return;
        }
        while(index <= ptr2){
            if(nums[index] == 0){
                swap(nums[++ptr1], nums[index++]);
            }
            
            else if(nums[index] == 2){
                swap(nums[ptr2], nums[index]);
                ptr2--;
            }
            
            else{
                index++;
            }
        }
    }
};