#include<vector>
#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> ump;
        for(int i=0;i<nums.size();i++){
            int conjugate = target - nums[i];
            if(ump.find(conjugate) != ump.end()){
                ans.push_back(ump[conjugate]);
                ans.push_back(i);
                return ans;
            }
            ump[nums[i]]=i;
        }
        return ans;
    }
};
