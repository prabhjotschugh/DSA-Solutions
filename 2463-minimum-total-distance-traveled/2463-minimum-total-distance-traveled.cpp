class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size();

        vector<int> fact;
        for (auto it : factory) {
            int pos = it[0];
            int limit = it[1];
            for (int i = 0; i < limit; i++) {
                fact.push_back(pos);
            }
        }
        int m = fact.size();
        vector<vector<long long>> dp(n + 1,
                                     vector<long long>(m + 1, LONG_MAX / 10));

        for (int factPos = 0; factPos <= m; factPos++) {
            dp[0][factPos] = 0;
        }

        for (int roboPos = 1; roboPos <= n; roboPos++) {
            for (int factPos = 1; factPos <= m; factPos++) {
                long long pick = abs(robot[roboPos - 1] - fact[factPos - 1]) +
                                 dp[roboPos - 1][factPos - 1];
                long long notPick = dp[roboPos][factPos - 1];
                dp[roboPos][factPos] = min(pick, notPick);
            }
        }
        return dp[n][m];
    }
};