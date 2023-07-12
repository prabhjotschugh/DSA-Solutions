class Solution {
public:
    bool checkValidString(string s) {
       int maxDiff = 0, minDiff = 0;
        for (char c : s) {
            maxDiff += (c == '(' || c == '*') ? 1 : -1;
            minDiff += (c == ')' || c == '*') ? -1 : 1;
            if (maxDiff < 0) return false;
            minDiff = max(0, minDiff);
        }
        return minDiff == 0; 
    }
};