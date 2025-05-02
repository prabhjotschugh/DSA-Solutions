class Solution {
public:
    string pushDominoes(string dom) {
        int len = dom.length();
        for (int i = 0; i < len; i++) {
            if (dom[i] == '.') {
                int j = i + 1;

                while (j < len && dom[j] == '.')
                    j++;

                // handling edge cases
                if (i == 0) {
                    if (j < len && dom[j] == 'L') {
                        while (i < j) {
                            dom[i] = 'L';
                            i++;
                        }
                    }
                    continue;
                } else if (j == len) {
                    if (dom[i - 1] == 'R') {
                        while (i < j) {
                            dom[i] = 'R';
                            i++;
                        }
                    }
                    i=j;
                    continue;
                }

                if (dom[i - 1] == 'R' && dom[j] != 'L') {
                    while (i != j) {
                        dom[i] = 'R';
                        i++;
                    }

                } else if (dom[j] == 'L' && dom[i - 1] != 'R') {
                    while (i != j) {
                        dom[i] = 'L';
                        i++;
                    }
                } else if (dom[i - 1] == 'R' && dom[j] == 'L') {
                    int diff = j - i;
                    int half = i + (diff / 2);
                    while (i < half) {
                        dom[i] = 'R';
                        i++;
                    }
                    if (diff % 2 == 1)
                        i++;
                    while (i < j) {
                        dom[i] = 'L';
                        i++;
                    }
                }
            }
        }

        return dom;
    }
};