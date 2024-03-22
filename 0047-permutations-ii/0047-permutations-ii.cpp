class Solution {
public:
    void bt(vector<vector<int>> &ans, vector<int> &p, vector<int> &nums, vector<bool> &v) {
        if(p.size() == nums.size()) {
            ans.push_back(p);
            return;
        }
        set<int> st;
        for(int i=0; i<nums.size(); i++) {
            if(!v[i] && st.find(nums[i]) == st.end()) {
                v[i] = true;
                p.push_back(nums[i]);
                st.insert(nums[i]);
                bt(ans, p, nums, v);
                v[i] = false;
                p.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> p;
        vector<bool> v(nums.size(), false);
        bt(ans, p, nums, v);
        return ans;
    }
};