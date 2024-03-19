class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m[128] = {0};
        for (char c : tasks)  m[c]++;  
        sort(m, m + 128, [](int a, int b){ return a > b; });
        int gap = n * (m[0] - 1), total = m[0] + gap;
        for (int i=1; i<128 && m[i] != 0; i++) {
            if (gap >= m[i]) {
                if (m[i] == m[0]) {
                    gap -= (m[0] - 1);      
                    total++;
                } else {
                    gap -= m[i];
                }
            } else {
                return tasks.size();
            }
        } 
        return total;
    }
};