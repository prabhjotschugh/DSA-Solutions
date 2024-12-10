class Solution {
public:
    int maximumLength(string s) {
        int n = s.size(), max_len = -1;
        for (int len = 1; len <= n; ++len) {
            unordered_map<string, int> freq;
            for (int i = 0; i <= n - len; ++i) {
                string sub = s.substr(i, len);
                bool is_special = true;
                for (int j = 1; j < len; ++j) {
                    if (sub[j] != sub[0]) {
                        is_special = false;
                        break;
                    }
                }
                if (is_special) {
                    freq[sub]++;
                    if (freq[sub] >= 3)
                        max_len = max(max_len, len);
                }
            }
        }
        return max_len;
    }
};