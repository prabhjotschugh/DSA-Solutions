class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int maxVal = 0, ans = 0;

        for (auto& event : events) {
            int start = event[0], end = event[1], value = event[2];
            while (!pq.empty() && pq.top().first < start) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }
            ans = max(ans, maxVal + value);
            pq.push({end, value});
        }

        return ans;   
    }
};