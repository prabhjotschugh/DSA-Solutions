class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long totalSize = 0; 
        for (char c : s) {
            if (isdigit(c)) {
                int digit = c - '0';
                totalSize *= digit;
            } else {
                totalSize++;
            }
        }
        
        for (int i = s.size() - 1; i >= 0; i--) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                int digit = currentChar - '0';
                totalSize /= digit;
                k %= totalSize;
            } else {
                if (k == 0 || k == totalSize) {
                    return string(1, currentChar); 
                }
                totalSize--;
            }
        }
        
        return "";
    }
};