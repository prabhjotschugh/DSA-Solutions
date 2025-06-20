class Solution {
public:
    int maxDistance(string s, int k) {
        int x = 0, y = 0;
        vector<int> distances;

        for (char move : s) {
            if (move == 'N') y++;
            else if (move == 'S') y--;
            else if (move == 'E') x++;
            else if (move == 'W') x--;
            distances.push_back(abs(x) + abs(y));
        }

        if (k == 0) {
            return *max_element(distances.begin(), distances.end());
        }

        int maxDist = distances[1];
        int prev = distances[0];
        int addedBoost = 0;

        for (int i = 1; i < distances.size(); ++i) {
            if (distances[i] < prev && k > 0) {
                addedBoost += 2;
                k--;
            }
            prev = distances[i];
            distances[i] += addedBoost;
            maxDist = max(maxDist, distances[i]);
        }

        return maxDist;
    }
};