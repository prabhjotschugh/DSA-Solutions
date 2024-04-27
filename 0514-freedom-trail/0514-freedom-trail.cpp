class Solution {
public:
    unordered_map<char, vector<int>> index;
    int find(int i, string &key, string &ring, int j, vector<vector<int>> &memo) {
        if(i>=key.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        char currChar = key[i];
        int ans = INT_MAX;
        for(int ind: index[currChar]) {
            int lftRotateStep = abs(ind-j);
            int rgtRotateStep = ring.size()-abs(ind-j);
            ans = min(ans, min(lftRotateStep,rgtRotateStep)+find(i+1,key,ring,ind,memo));
        }
        return memo[i][j] = 1+ans;
    }
    
    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1,-1));
        for(int i=0; i<ring.size(); i++) {
            index[ring[i]].push_back(i);
        }
        return find(0,key,ring,0,memo);
    }
};