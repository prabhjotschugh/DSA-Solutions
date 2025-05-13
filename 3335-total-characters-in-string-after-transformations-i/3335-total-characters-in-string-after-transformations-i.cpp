#include <vector>
#include <string>

class Solution {
public:
    int lengthAfterTransformations(std::string s, int t) {
        const int MOD = 1000000007;
        std::vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (int j = 0; j < t; j++) {
            std::vector<int> tmp(26, 0);
            for (int i = 0; i < 26; i++) {
                if (i == 25) {
                    tmp[0] = (tmp[0] + cnt[i]) % MOD;
                    tmp[1] = (tmp[1] + cnt[i]) % MOD;
                } else {
                    tmp[i + 1] = (tmp[i + 1] + cnt[i]) % MOD;
                }
            }
            cnt = tmp;
        }

        int len = 0;
        for (int c : cnt) {
            len = (len + c) % MOD;
        }

        return len;
    }
};