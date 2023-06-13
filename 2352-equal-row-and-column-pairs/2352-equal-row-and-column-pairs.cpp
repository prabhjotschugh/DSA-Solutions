class Solution {
public:
    int equalPairs(vector<vector<int>>& v) {
        int n=v.size();
        int r=0;
        vector<vector<int>>c = v;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)swap(v[i][j],v[j][i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i]==c[j])r++;
            }
        }
        return r;
    }
};