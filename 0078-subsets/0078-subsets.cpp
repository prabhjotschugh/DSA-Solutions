class Solution {
public:
    int n;
    vector<vector<int>> subsets(vector<int>& a) {
        n = a.size();
        vector<vector<int>> res;
        vector<int> curr;
        backTrack(res,0,curr,a);
        return res;
    }

    void backTrack(vector<vector<int>>& res, int ind, vector<int> curr, vector<int>& a) {
        if(ind==n) {
            res.push_back(curr);
            return;
        }
        backTrack(res, ind+1, curr, a);
        curr.push_back(a[ind]);
        backTrack(res, ind+1, curr, a);
    }
};