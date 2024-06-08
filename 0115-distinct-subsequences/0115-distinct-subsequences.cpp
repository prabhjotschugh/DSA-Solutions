class Solution {
public:
    int dp[1001][1001];
    int solve(int currentInd, int currentTarIn, string &s, string &t) {
      if(currentTarIn >= (t.size())) {
        return 1;
      }
      if(currentInd>=(s.size())) {
        return 0;
      }
      if(dp[currentInd][currentTarIn] != -1) {
        return dp[currentInd][currentTarIn];
      }
      int res1 = solve(currentInd + 1, currentTarIn, s, t);
      if(s[currentInd] == t[currentTarIn]) {
        res1 += solve(currentInd + 1, currentTarIn + 1, s, t);
      }
      return dp[currentInd][currentTarIn] = res1;
    }
    
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, t);
    }
};