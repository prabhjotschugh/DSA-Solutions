class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(st.size() == 0 || st.top() == ')'){
                    st.push(s[i]);
                }else{
                    st.pop();
                }
            }
        }
        return st.size();
    }
};