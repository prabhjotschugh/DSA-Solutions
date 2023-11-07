class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++) time[i] = (dist[i] + speed[i] - 1) / speed[i];
        sort(time.begin(), time.end());

        int result = 0;
        int curr_time = 0;
        for (const int& t : time) {
            if (curr_time >= t) return result;
            result++;
            curr_time++;
        }
        return result;
    }
};