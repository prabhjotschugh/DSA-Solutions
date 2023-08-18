class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<pair<int,int>,int> mp;
        vector<int> degree(n,0);
        
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0], v=roads[i][1];
            mp[{u,v}]++;
            
            degree[u]++, degree[v]++;
        }
        
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int c = degree[i]+degree[j];
                c -= (mp[{i,j}] + mp[{j,i}]);
                
                ans = max(ans,c);
            }
        }
        
        return ans;
    }
};