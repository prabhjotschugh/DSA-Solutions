class Solution {
public:
    unordered_set<int> freq;
    inline bool elementPresent(int element){
        return freq.count(element);
    }
    
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(!elementPresent(nums[i])){
                freq.insert(nums[i]);
                nums[index] = nums[i];
                index++;
            }else{
                continue;
            }
        }
        return freq.size();
    }
};