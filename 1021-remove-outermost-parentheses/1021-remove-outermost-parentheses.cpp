class Solution {
public:
    string removeOuterParentheses(string s) {
        int brackets = 0;
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' && brackets++ > 0){
                ans += s[i];
            }
            if(s[i] == ')' && brackets-- > 1){
                ans += s[i];
            }
        }
        return ans;
    }
};