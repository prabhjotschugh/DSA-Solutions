class Solution {
public:
    string shortestPalindrome(string s) {
        if(s == "") return s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s+"@"+rev;

        int n = str.length();
        vector<int> lps(n, 0);
        int i = 0; 
        for (int j = 1; j < n; ) {
            if (str[i] == str[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            } else {
                if (i != 0) {
                    i = lps[i - 1]; 
                } else {
                    lps[j] = 0; 
                    j++;
                }
            }
        }
        string temp = s.substr(i);
        reverse(temp.begin(), temp.end());
        return temp+s;
    }
};