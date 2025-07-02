class Solution {
public:
    long long mod = 1e9 + 7;

    long long solve(vector<int>& extra, int req) {
        if (req < 0) return 0;
        vector<long long> dp(req + 1, 0);
        dp[0] = 1;

        for (int x : extra) {
            vector<long long> new_dp(req + 1, 0);
            vector<long long> prefix(req + 2, 0);

            for (int j = 0; j <= req; ++j) {
                prefix[j + 1] = (prefix[j] + dp[j]) % mod;
            }

            for (int j = 0; j <= req; ++j) {
                int l = max(0, j - x);
                int r = j;
                new_dp[j] = (prefix[r + 1] - prefix[l] + mod) % mod;
            }

            dp = new_dp;
        }

        long long total = 0;
        for (int i = 0; i <= req; ++i) {
            total = (total + dp[i]) % mod;
        }

        return total;
    }

    int possibleStringCount(string s, int k) {
        vector<int> extra;
        int len = 0, i = 1;
        int cnt = 1;

        while (i < s.length()) {
            if (s[i] == s[i - 1]) len++;
            else {
                cnt++;
                if (len > 0) extra.push_back(len);
                len = 0;
            }
            i++;
        }

        if (len > 0) {
            extra.push_back(len);
        }

        int req = k - cnt;
        long long val = 1;
        for (auto x : extra) {
            val = (val * 1LL * (x + 1)) % mod;
        }

        long long temp = solve(extra, req - 1);
        return (val - temp + mod) % mod;
    }
};