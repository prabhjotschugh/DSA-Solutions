class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int mini = 1e9, maxi = -1e9;

        for (int i = 0; i < n; i++) {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            pq.push({nums[i][0], {i, 0}});
        }

        int ansMin = mini;
        int ansMax = maxi;
        int diff = maxi - mini;

        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int miniVal = it.first;  
            int row = it.second.first; 
            int col = it.second.second; 

            if (maxi - miniVal < diff) {
                ansMin = miniVal;
                ansMax = maxi;
                diff = maxi - miniVal;
            }

            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                pq.push({nextVal, {row, col + 1}});
                maxi = max(maxi, nextVal);
            } else {
                break;
            }
        }

        return {ansMin, ansMax};
    }
};