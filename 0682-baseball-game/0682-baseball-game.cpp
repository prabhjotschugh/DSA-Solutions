class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto op: operations){
            if(op == "+"){
                int num = st.top();
                st.pop();
                int newNum = st.top() + num;
                st.push(num);
                st.push(newNum);
            }else if(op == "D"){
                st.push(2*st.top());
            }else if(op == "C"){
                st.pop();
            }else{
                st.push(stoi(op));
            }
        }
        
        int sum = 0;
        while(st.size()>0){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};