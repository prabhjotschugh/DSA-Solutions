class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const int mod = 1e9 + 7;
        vector<vector<int>> matrix(26, vector<int>(26, 0));
        
        for (int c = 0; c < 26; c++) {
            int num = nums[c];
            for (int j = 1; j <= num; j++) {
                int next_c = (c + j) % 26;
                matrix[c][next_c]++;
            }
        }

        auto matrix_multi = [&](vector<vector<int>>& x, vector<vector<int>>& y) {
            vector<vector<int>> res(26, vector<int>(26, 0));
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    for (int l = 0; l < 26; l++) {
                        res[i][l] = (res[i][l] + 1LL * x[i][j] * y[j][l]) % mod;
                    }
                }
            }
            return res;
        };

        auto matrix_pol = [&](vector<vector<int>>& m, int n) {
            vector<vector<int>> total(26, vector<int>(26, 0));
            for (int i = 0; i < 26; i++) {
                total[i][i] = 1; 
            }

            while (n > 0) {
                if (n % 2 == 1) {
                    total = matrix_multi(total, m);
                }
                m = matrix_multi(m, m);
                n /= 2;
            }

            return total;
        };


        vector<vector<int>> compute = matrix_pol(matrix, t);

        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        vector<int> new_cnt(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                new_cnt[j] = (new_cnt[j] + 1LL * cnt[i] * compute[i][j]) % mod;
            }
        }


        int result = 0;
        for (int x : new_cnt) {
            result = (result + x) % mod;
        }

        return result;
    }
};