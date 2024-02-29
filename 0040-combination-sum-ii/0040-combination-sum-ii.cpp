class Solution {
public:
    void solve(int index,vector<int>& ds,int target,vector<int>& arr,int n,vector<vector<int>>& temp){
            if(target == 0){
                temp.push_back(ds); 
                return;
            }
            for(int i=index;i<arr.size();i++){
            if(i>index && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            solve(i+1,ds,target-arr[i],arr,n,temp);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> temp;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(0,ds,target,candidates,n,temp);
        return temp;
    }
};