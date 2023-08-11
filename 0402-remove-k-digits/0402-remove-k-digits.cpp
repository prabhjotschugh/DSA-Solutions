class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()<=k){
            return "0";
        }
        if(k==0){
            return num;
        }
        string res="";
        stack<char>st;
        st.push(num[0]);
        for(int i=1;i<num.length();i++){
            while(k>0 and !st.empty() and num[i]<st.top()){
                k--;
                st.pop();
            }
            st.push(num[i]);
            if(st.size()==1 and num[i]=='0'){
                st.pop();
            }
        }
        while(k and !st.empty()){
            k--;
            st.pop();
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        if(res.length()==0){
            return "0";
        }
        return res;
    }
};