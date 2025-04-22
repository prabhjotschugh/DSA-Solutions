class Solution {
public:
    bool handle_exp(string& s, int i) {
        if(s[i]!='e' && s[i]!='E')
        return false;
        
        if(s[i-1]=='+'|| s[i-1]=='-')return false;
        if(s[i-1]=='.')
        {
            if(i-2<0)return false;
            if(!isdigit(s[i-2]))return false;
        }
        i++;
        int n=s.length();
        if (i == n)
            return false;
        if (s[i] == '+' || s[i] == '-'){
            i++;
        }
        if (i == n)
            return false;
        while (i < n) 
        {
            if (!isdigit(s[i]))
                return false;
            i++;
        }
        return true;
    }
bool handle_dec(string &s,int i)
{
    int n=s.length();
    if(n==1)return false;
    if(i-1>=0 && (s[i-1]=='+' || s[i-1]=='-'))
    {
        if(i+1==n)return false;
    }
    return true;
}
bool handle_sign(string s,int i)
{
    if(s.length()==1)return false;
    if(i==0)return true;
    return false;
}
    bool isNumber(string s) {

        int n = s.length();
        bool before_digit = false;
        bool after_digit = false;
        bool decimal = false;
        int i = 0;
        while (i < n)
        {
            if (isdigit(s[i])) 
            {
                i++;
            }
            else if (isalpha(s[i])) 
            {
                if(i==0)return false;
                return handle_exp(s,i);
            }
            else if(s[i]=='.')
            {
                if(decimal)return false;
                decimal=true;
                if(!handle_dec(s,i))
                return false;
                i++;
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                if(!handle_sign(s,i))return false;
                i++;
            }
        
        }
        return true;
    }
};