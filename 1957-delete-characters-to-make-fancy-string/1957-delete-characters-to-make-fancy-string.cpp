class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        if (s.size() == 1)
            return s;
        ans.push_back(s[0]);
        ans.push_back(s[1]);
        for (int i = 2; i < s.size(); i++) {
            if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
                continue;
            } else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};