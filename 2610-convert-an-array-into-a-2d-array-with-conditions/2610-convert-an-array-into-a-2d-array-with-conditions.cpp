class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> s;
        while (!nums.empty()) {
            vector<int> uniqueRow;
            
            for (int i = 0; i < nums.size(); i++) {
                if (s.find(nums[i]) == s.end()) {
                    s.insert(nums[i]);
                    uniqueRow.push_back(nums[i]);
                    nums.erase(nums.begin() + i);
                    i--;  
                }
            }
            ans.push_back(uniqueRow);
            s.clear();  
        }
        return ans;   
    }
};