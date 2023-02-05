class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            int jumps = 2 * (numRows - 1);  //no of jumps to do for reaching the next element of row
            for (int j = i; j < s.length(); j += jumps) {   // increment j always by jumps
                ans += s[j];
                int midJumps = j + jumps - 2 * i;   // jumps for middle rows 
                if (i > 0 && i < numRows - 1 && midJumps < s.length())  // check if middle jumps are in range
                    ans += s[midJumps];
            }
        }
        return ans;
    }
};