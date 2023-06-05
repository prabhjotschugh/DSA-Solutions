class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> present;
        unordered_map<int, bool> checked;
        
        for(auto i:nums){
            present[i] = true;
        }
        
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(!checked[nums[i]]  && !present[nums[i] - 1]){
                int chain = 0;
                int start = nums[i];

                while(present[start]){
                    start++;
                    chain++;
                    checked[nums[i]] = true; 
                }
                
                maxi = max(maxi, chain);
            }
        }
        return maxi;
    }
};