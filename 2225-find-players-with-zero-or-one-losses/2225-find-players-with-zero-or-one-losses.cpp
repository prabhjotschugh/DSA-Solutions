class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(int i=0;i<matches.size();i++){
            int winner = matches[i][0];
            int loser = matches[i][1];
            
            mp[winner]++;
            mp[winner]--;
            mp[loser]--;
        }
        
        vector<vector<int>> dp(2);
        for(auto x : mp){
            if(x.second == 0){
                dp[0].push_back(x.first);
            }
            else if(x.second == -1){
                dp[1].push_back(x.first);
            }
        }
        return dp;
    }
};