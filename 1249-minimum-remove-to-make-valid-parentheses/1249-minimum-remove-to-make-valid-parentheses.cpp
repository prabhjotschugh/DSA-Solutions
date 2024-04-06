class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close = 0;
        stack<char>st;
        for (const char& c : s) {
            if (c != '(' && c != ')') {
                st.push(c);
            } else if (c == '(') {
                open++;
                st.push(c);
            } else if (open > 0) {
                st.push(c);
                open--;
            }
        }
        string ans;
            open = 0, close = 0;
            while(!st.empty()) {
                char c = st.top();
                st.pop();
                if (c != '(' && c != ')') {
                    ans += c;
                } else if (c == ')') {
                    close++;
                    ans += c;
                } else if (close > 0) {
                    ans += c;
                    close--;
                }
            }
        
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};