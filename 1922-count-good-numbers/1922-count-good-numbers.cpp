class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evens = (n + 1) / 2;
        long long odds = n / 2;
        long long evenPart = modExp(5, evens, MOD);
        long long oddPart = modExp(4, odds, MOD);
        return (evenPart * oddPart) % MOD;
    }
};