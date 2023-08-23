class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        if(n==1) return s;
        
        int i=0;
        int j=1;
        bool flag=false;
        while(j<n){
            if(s[i]==s[j]){
                i=j;
                while(j<n && s[i]==s[j]){
                    j++;
                }
                if(j==n){
                flag=true;
                continue;
                } 
                swap(s[i],s[j]);
            }
            i++;
            j=i+1;
        }
        if(flag){
            reverse(s.begin(),s.end());
            i=0;
            j=i+1;
            while(j<n){
                if(s[i]==s[j]){
                    i=j;
                    while(s[i]==s[j]) j++;
                    if(j==n){
                        return "";
                    } 
                    swap(s[i],s[j]);
                }
                i++;
                j=i+1;
            }
        }
        return s;
    }
};