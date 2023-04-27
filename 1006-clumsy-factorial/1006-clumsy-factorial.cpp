class Solution {
public:
    int clumsy(int n) {
        char op[4] = {'*', '/', '+', '-'};
        stack<int>st;
        st.push(n--);
        int ind = 0;
        while(n > 0) {
            int top = st.top();
            st.pop();
            if(op[ind] == '*')st.push(top * n--);
            else if(op[ind] == '/')st.push(top / n--);
            else if(op[ind] == '+')st.push(top + n--);
            else st.push(top), st.push((-1 * n--));
            ind = (ind + 1) % 4;
        }
        int sum = 0;
        while(!st.empty()) sum += st.top(), st.pop();
        return sum;
    }
};