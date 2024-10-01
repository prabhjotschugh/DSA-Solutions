class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> f(k);
        for (int x : arr) f[(x % k + k) % k]++;
        if (f[0] % 2) return false;
        for (int i{1}; i <= k / 2; ++i) if (f[i] != f[k - i]) return false;
        return true;
    }
};