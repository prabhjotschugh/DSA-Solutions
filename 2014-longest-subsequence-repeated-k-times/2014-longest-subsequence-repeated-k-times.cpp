class Solution {
public:
    bool isKRepeatedSubsequence(const string& s, const string& pattern, int k) {
        int pos = 0, matched = 0;
        int m = pattern.size();

        for (char ch : s) {
            if (ch == pattern[pos]) {
                pos++;
                if (pos == m) {
                    pos = 0;
                    matched++;
                    if (matched == k) return true;
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;

        vector<char> candidates;
        for (int i = 25; i >= 0; --i) {
            if (freq[i] >= k) candidates.push_back('a' + i);
        }

        queue<string> q;
        string ans = "";

        for (char ch : candidates) {
            q.push(string(1, ch));
        }

        while (!q.empty()) {
            string curr = q.front(); q.pop();

            if (curr.size() > ans.size() || (curr.size() == ans.size() && curr > ans)) {
                if (isKRepeatedSubsequence(s, curr, k)) ans = curr;
            }

            if (curr.size() == 7) continue;

            for (char ch : candidates) {
                string next = curr + ch;
                if (isKRepeatedSubsequence(s, next, k)) q.push(next);
            }
        }

        return ans;
    }
};