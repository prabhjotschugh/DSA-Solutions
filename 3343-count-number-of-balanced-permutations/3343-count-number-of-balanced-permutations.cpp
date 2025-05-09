#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
    vector<int> fact, inv, invFact;

    void precompute(int n) {
        fact.assign(n + 1, 1);
        inv.assign(n + 1, 1);
        invFact.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            fact[i] = (1LL * fact[i - 1] * i) % MOD;

        inv[1] = 1;
        for (int i = 2; i <= n; i++)
            inv[i] = MOD - 1LL * (MOD / i) * inv[MOD % i] % MOD;

        for (int i = 1; i <= n; i++)
            invFact[i] = (1LL * invFact[i - 1] * inv[i]) % MOD;
    }

public:
    int countBalancedPermutations(string num) {
        int n = num.size(), sum = 0;
        for (char c : num)
            sum += c - '0';

        if (sum % 2 == 1) return 0;

        precompute(n);
        int halfSum = sum / 2;
        int halfLen = n / 2;

        vector<vector<int>> dp(halfSum + 1, vector<int>(halfLen + 1));
        dp[0][0] = 1;

        vector<int> digits(10, 0);
        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';
            digits[d]++;
            for (int s = halfSum; s >= d; s--) {
                for (int l = halfLen; l >= 1; l--) {
                    dp[s][l] = (dp[s][l] + dp[s - d][l - 1]) % MOD;
                }
            }
        }

        int res = dp[halfSum][halfLen];
        res = 1LL * res * fact[halfLen] % MOD;
        res = 1LL * res * fact[n - halfLen] % MOD;

        for (int cnt : digits) {
            res = 1LL * res * invFact[cnt] % MOD;
        }

        return res;
    }
};