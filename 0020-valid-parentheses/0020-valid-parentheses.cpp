class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i=0;i<s.length();i++){
            if(stack.empty()){
                stack.push(s[i]);
            }
            else if((stack.top()=='(' && s[i]==')') ||
               (stack.top()=='{' && s[i]=='}') ||
               (stack.top()=='[' && s[i]==']')){
                stack.pop();
            }
            else{
                stack.push(s[i]);
            }
            
        }
        if(stack.empty()){
            return true;
        }else{
            return false;
        }
    }
};