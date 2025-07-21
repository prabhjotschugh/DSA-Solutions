class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        int count = 1;
        string res = "";
        res += s[0]; 

        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                count++;
            }else{
                count = 1;
            }
            if(count < 3){
                res += s[i];
            }
        }
        return res;
    }
};