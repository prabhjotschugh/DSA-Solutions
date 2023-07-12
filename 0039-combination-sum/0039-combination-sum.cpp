class Solution {
public:
    void solve(vector<int>& arr, int tar, int index, vector<vector<int>>&ans, vector<int>&smallAns){
        if(tar == 0){
            vector<int> base;
            for(int i:smallAns){
                base.push_back(i);
            }
            ans.push_back(base);
            return;
        }
        
        for(int i=index;i<arr.size();i++){
            if(tar - arr[i] >= 0){
                smallAns.push_back(arr[i]);
                solve(arr, tar-arr[i],i,ans,smallAns);
                smallAns.pop_back();
            }
        }        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>>ans;
        vector<int>smallAns;
        solve(arr, tar, 0, ans, smallAns);
        return ans;
    }
};