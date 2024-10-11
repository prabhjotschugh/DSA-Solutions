class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1);
        int tar = times[targetFriend][0];
        sort(times.begin(), times.end());
        for (auto it : times) {
            int arr = it[0];
            int dep = it[1];
            for (int i = 0; i < n; i++) {
                if (arr >= chairs[i]) {
                    chairs[i] = dep;
                    if (arr == tar)
                        return i;
                    break;
                }
            }
        }
        return -1;
    }
};