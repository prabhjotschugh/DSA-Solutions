class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), l{0}, r = n - 1;
        while (l + 1 < n && arr[l] <= arr[l + 1]) ++l;
        if (l == n - 1) return 0;
        while (r > l && arr[r - 1] <= arr[r]) --r;
        int res = min(n - l - 1, r);
        for (int i{0}, j = r; i <= l && j < n; ) 
            arr[i] <= arr[j] ? res = min(res, j - i++ - 1) : ++j;
        return res;
    }
};