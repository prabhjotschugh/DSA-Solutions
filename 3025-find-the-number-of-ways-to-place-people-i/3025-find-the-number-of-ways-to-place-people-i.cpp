class Solution {
public:
    static bool cmp(vector<int>& p, vector<int>& q){
        return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];
    }

    int numberOfPairs(vector<vector<int>>& P) {
        sort(P.begin(), P.end(), cmp);
        int n = P.size(), ans = 0;
        for(int i=0; i<n-1; i++){
            int y=INT_MAX;
            for(int j = i+1; j<n; j++){
                if (P[j][1]>=P[i][1] && y>P[j][1]){
                    ans++;
                    y=P[j][1];
                }
            }
        }
        return ans;
    }
};