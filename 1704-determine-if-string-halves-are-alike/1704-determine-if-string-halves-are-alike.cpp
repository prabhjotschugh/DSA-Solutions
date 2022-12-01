class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.length();
        int v1=0,v2=0;
        for(int i=0;i<len/2;i++){
            if(s[i]=='a'||s[i]=='A'||
               s[i]=='e'||s[i]=='E'||
               s[i]=='i'||s[i]=='I'||
               s[i]=='o'||s[i]=='O'||
               s[i]=='u'||s[i]=='U'){
                v1++;
            }
        }
        
        for(int i=len/2;i<len;i++){
            if(s[i]=='a'||s[i]=='A'||
               s[i]=='e'||s[i]=='E'||
               s[i]=='i'||s[i]=='I'||
               s[i]=='o'||s[i]=='O'||
               s[i]=='u'||s[i]=='U'){
                v2++;
            }
        }
        
        if(v1==v2) return true;
        else return false;
    }
};