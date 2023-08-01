class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        for(int i=0;i<(1<<n) ;i++){
            vector<int>v;
            int f = __builtin_popcountll(i);
            if(f!=k)continue;
            for(int j=0;j<n;j++){
                if((1<<j) & i){
                    v.push_back(j+1);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};