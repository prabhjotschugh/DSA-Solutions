#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; ++i) free.push(i);

        using T = pair<long long,int>;           
        priority_queue<T, vector<T>, greater<T>> busy;

        vector<int> cnt(n, 0);

        for (auto& m : meetings) {
            long long s = m[0], e = m[1];

            while (!busy.empty() && busy.top().first <= s) {
                free.push(busy.top().second);
                busy.pop();
            }

            int room;
            long long newEnd;
            if (!free.empty()) {
                room = free.top(); free.pop();
                newEnd = e;
            } else {
                auto [endTime, r] = busy.top(); busy.pop();
                room = r;
                newEnd = endTime + (e - s);
            }
            busy.emplace(newEnd, room);
            ++cnt[room];
        }

        return int(max_element(cnt.begin(), cnt.end()) - cnt.begin());
    }
};