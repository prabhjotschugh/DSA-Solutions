class Solution { 
public:
    int numTilePossibilities(std::string tiles) {
        int n = tiles.length();
        std::vector<int> counts(26, 0);
        std::vector<int> fac(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fac[i] = i * fac[i - 1];
        }
        for (char c : tiles) {
            counts[c - 'A']++;
        }
        std::vector<int> lengthcounts(n + 1, 0);
        lengthcounts[0] = 1;
        for (int i = 0; i < 26; i++) {
            if (counts[i] > 0) {
                std::vector<int> temp(n + 1, 0);
                for (int j = 0; j <= n && lengthcounts[j] > 0; j++) {
                    for (int k = 1; k <= counts[i]; k++) {
                        int totallength = j + k;
                        temp[totallength] += lengthcounts[j] * fac[totallength] / (fac[k] * fac[j]);
                    }
                }
                for (int j = 0; j <= n; j++) {
                    lengthcounts[j] += temp[j];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += lengthcounts[i];
        }
        return ans;
    }
};