#include<string>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return 0;
        }
        
        stringstream ss;  
        ss<<x;  
        string s;  
        ss>>s;  
        for(int i=0;i<(s.length()/2);i++){
            if(s[i]!=s[s.length()-i-1]){
                return 0;
            }
        }
        return 1;
    }
};