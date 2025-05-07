#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        vector<vector<int>> bestTime(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int ans = INT_MAX;

        // Helper function
        function<void(int, int, int)> helper = [&](int i, int j, int time) {
            if (time >= bestTime[i][j]) return;
            bestTime[i][j] = time;

            if (i == n - 1 && j == m - 1) {
                ans = min(ans, time);
                return;
            }

            for (auto& d : dir) {
                int x = i + d[0];
                int y = j + d[1];
                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    visited[x][y] = true;
                    int wait = moveTime[x][y];
                    int nextTime = wait > time ? wait + 1 : time + 1;
                    if (i == 0 && j == 0 && wait <= time) {
                        nextTime = 1 + wait;
                    }
                    helper(x, y, nextTime);
                    visited[x][y] = false;
                }
            }
        };

        visited[0][0] = true;
        helper(0, 0, 0);
        return ans;
    }
};