class Solution {
public:
    int maxDepth(string s) {
        stack<char> stack; 
        int mx = 0; 
        for (char c : s) { 
            if (c == '(') { 
                stack.push(c); 
            } else if (c == ')') {
                mx = max((int)stack.size(), mx);
                stack.pop(); 
            }
        }
        return mx; 
    }
};