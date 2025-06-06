class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string result;
        stack<int> stk;

        auto hasSmaller = [&](int top) {
            for (int i = 0; i < top; i++) {
                if (freq[i] > 0) return true;
            }
            return false;
        };

        for (char c : s) {
            int ch = c - 'a';
            freq[ch]--;
            stk.push(ch);

            while (!stk.empty() && !hasSmaller(stk.top())) {
                result += (char)(stk.top() + 'a');
                stk.pop();
            }
        }

        return result;
    }
};
