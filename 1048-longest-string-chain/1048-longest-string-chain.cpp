class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if (n == 1) return 1;
        sort(words.begin(), words.end(), [&](string& x, string& y) {
            return x.size() < y.size(); 
        });
        vector<unordered_map<string, int>> mp(17);
        for (auto& w : words)
            mp[w.size()][w] = 1;

        int ans = 0;

        for (auto& w : words) {
            int sz = w.size();
            if (sz == 1) continue;
            for (int i = 0; i < sz; i++) {
                string w2 = w.substr(0, i) + w.substr(i+1); 
                if (mp[sz-1].count(w2) != 0) {
                    mp[sz][w] = max(mp[sz][w], mp[sz-1][w2] + 1);
                }
            }
            ans = max(ans, mp[sz][w]);
        }
        return ans;
    }
};