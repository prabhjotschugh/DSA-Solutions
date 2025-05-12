using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int i : digits) freq[i]++;

        int last[10], middle[10], first[10], res[900];
        int n1 = 0, n2 = 0, n3 = 0, size = 0;

        for (int i = 0; i < 10; i++) {
            if (freq[i] == 0) continue;
            if (i % 2 == 0) last[n3++] = i;
            if (i > 0) first[n1++] = i;
            middle[n2++] = i;
        }

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                for (int k = 0; k < n3; k++) {
                    int a = first[i], b = middle[j], c = last[k];
                    int x = a * 100 + b * 10 + c;

                    if (a != b && b != c && a != c) {
                        res[size++] = x;
                    } else if ((a == b && b != c) || (a == c && a != b)) {
                        if (freq[a] > 1) res[size++] = x;
                    } else if (b == c && a != b) {
                        if (freq[b] > 1) res[size++] = x;
                    } else if (freq[a] > 2) {
                        res[size++] = x;
                    }
                }
            }
        }

        vector<int> ans(size);
        for (int i = 0; i < size; i++) ans[i] = res[i];
        return ans;
    }
};