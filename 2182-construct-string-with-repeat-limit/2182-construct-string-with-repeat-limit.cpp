class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[26] = {};
        string ans;
        for (char c : s) cnt[c - 'a']++;
        while (true) {
            int i = 25;
            bool onlyOne = false;
            for (; i >= 0; --i) {
                if (ans.size() && i == ans.back() - 'a' && cnt[i]) { 
                    onlyOne = true;
                    continue;
                }
                if (cnt[i]) break; 
            }
            if (i == -1) break; 
            int fill = onlyOne ? 1 : min(cnt[i], repeatLimit);
            cnt[i] -= fill;
            while (fill--) ans += 'a' + i;
        }
        return ans;
    }
};