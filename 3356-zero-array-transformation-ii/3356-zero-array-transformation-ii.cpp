#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int mid) {
        int n = nums.size();
        vector<int> temp(nums);
        vector<int> delta(n + 1, 0);

        for (int i = 0; i < mid; i++) {
            int l = queries[i][0], r = queries[i][1], v = queries[i][2];
            delta[l] -= v;
            if (r + 1 < n) delta[r + 1] += v;
        }

        int currDecrement = 0;
        for (int i = 0; i < n; i++) {
            currDecrement += delta[i];
            temp[i] += currDecrement;
            if (temp[i] > 0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size(), ans = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (isZeroArray(nums, queries, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};