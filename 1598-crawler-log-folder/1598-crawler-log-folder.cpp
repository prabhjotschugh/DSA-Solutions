class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> st;
        for(auto log: logs){
            if(log == "../"){
                if(st.empty()) 
                    continue;

                st.pop();
            }else if(log == "./"){
                continue;
            }else{
                st.push(1);
            }
            
        }
        return st.size();
    }
};