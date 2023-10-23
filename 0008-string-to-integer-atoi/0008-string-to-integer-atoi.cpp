class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int p=0;
        int c=0;
        double t=0;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='+'){
            c++;
            i++;
        }
        if(s[i]=='-'){
        p++;
        i++;
        }
        while(i<s.size()and s[i]>='0' and s[i]<='9')
        {
            t=t*10+(s[i]-'0');
            i++;
        }
        if(c>0&&p>0){
        return 0;
        }
        if(p>0){
          t=-t;
        }
         if(c>0){
            t=t;
        }
        if(t>INT_MAX){
            t=INT_MAX;
        }
        if(t<INT_MIN){
            t=INT_MIN;
        }
        return (int)t;
    }
};