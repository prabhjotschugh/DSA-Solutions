class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    int n = heights.size();
    int len = ceil(sqrt(n));
    vector<int> sq(len, INT_MIN), ans;

    for (int i = 0; i < n; i++) {
        sq[i / len] = max(sq[i / len], heights[i]);
    }

    for (auto q : queries) {
        int l = min(q[0], q[1]), r = max(q[0], q[1]);
        if (l == r || heights[l] < heights[r]) {
            ans.push_back(r);
            continue;
        }

        int target = max(heights[l], heights[r]);
        bool done = false;
        for (int i = r + 1; i < n;) {
            if (done) break;

            if (i % len == 0 && i + len - 1 < n) {
                if (sq[i / len] <= target) {
                    i += len;
                } else {
                    for (int j = i; j < i + len; j++) {
                        if (heights[j] > target) {
                            ans.push_back(j);
                            done = true;
                            break;
                        }
                    }
                }
            } else {
                if (heights[i] > target) {
                    ans.push_back(i);
                    done = true;
                }
                ++i;
            }
        }
        if (!done) {
            ans.push_back(-1);
        }
    }
    return ans;
}

};