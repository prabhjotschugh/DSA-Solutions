const int N = 1000;
int q[N], front, back;
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        const int n = status.size();
        bitset<N> canOpen = 0,  hasBox = 0;

        for (int i = 0; i < n; i++)
            canOpen[i] = status[i];

        front = back = 0; 
        for (int i : initialBoxes) {
            hasBox[i] = 1;
            if (canOpen[i]) {
                q[back++] = i;
            }
        }

        int ans = 0;
        while (front < back) {
            int i = q[front++];
            ans += candies[i];

            for (int k : keys[i]) {
                if (!canOpen[k]) {
                    canOpen[k] = 1;
                    if (hasBox[k]) {
                        q[back++] = k;
                    }
                }
            } 
            for (int j : containedBoxes[i]) {
                hasBox[j] = 1;
                if (canOpen[j] ) {
                    q[back++] = j;
                }
            }
        }
        return ans;
    }
};