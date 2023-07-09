class Solution {
public:
    int largestVariance(string s) {
        int max_result = 0;
        for (char from = 'a'; from <= 'z'; from++) {
            for (char to = 'a'; to <= 'z'; to++) {
                if (from == to) continue;
                int dp = 0;  
                int dp1 = INT_MIN;
                for (int i = 0; i < s.size(); i++) {
                    char c = s[i];
                    if (c == from) {
                        dp = max(1, dp+1);
                        if (dp1 != INT_MIN) dp1 = dp1 + 1;
                    } else if (c == to) {
                        if (dp1 == INT_MIN) {
                            dp1 = max(-1, dp-1);
                        } else {
                            dp1 = max(max(-1, dp-1), dp1 -1);
                        }
                        dp = dp -1;
                    }
                    max_result = max(max_result, dp1);
                }
            }
        }
        return max_result;
    }
};