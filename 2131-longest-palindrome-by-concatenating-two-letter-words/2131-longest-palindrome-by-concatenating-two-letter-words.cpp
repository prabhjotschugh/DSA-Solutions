#define n 26

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int len = 0, arr[n][n] = { 0 };
        for (string& s : words) {
            if (!arr[s.front() - 'a'][s.back() - 'a']) ++arr[s.back() - 'a'][s.front() - 'a'];
            else len += 4, --arr[s.front() - 'a'][s.back() - 'a'];
        }
        for (int i = 0; i < n; ++i) if (arr[i][i] & 1) {
            len += 2;
            break;
        }
        return len;
    }
};