class Solution {
private:
    static bool isNotNumber(const string &a) {
        try {
            int chk = stoi(a);
            return chk >= -200 && chk <= 200;
        } catch (...) {
            return false;  
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        ios::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0);
        int n = tokens.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (!isNotNumber(tokens[i])) {
                int k1 = st.top();
                st.pop();
                int k2 = st.top();
                st.pop();
                if (tokens[i] == "+") {
                    st.push(k1 + k2);
                } else if (tokens[i] == "-") {
                    st.push(k2 - k1);  
                } else if (tokens[i] == "*") {
                    st.push(k1 * k2);
                } else if (tokens[i] == "/") {
                    st.push(k2 / k1);
                }
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};