class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while(columnNumber>0){
            columnNumber -= 1;
            char ch = 'A' + columnNumber%26;
            s += ch;
            columnNumber /= 26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};