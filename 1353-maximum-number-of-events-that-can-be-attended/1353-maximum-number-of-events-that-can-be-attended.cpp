#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, n = events.size(), day = 1, count = 0;
        int lastDay = 0;

        for (const auto& e : events)
            lastDay = max(lastDay, e[1]);

        while (day <= lastDay && (i < n || !pq.empty())) {
            if (pq.empty() && i < n) {
                day = max(day, events[i][0]);
            }

            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            if (!pq.empty()) {
                pq.pop();
                count++;
            }

            day++;
        }

        return count;
    }
};