class Solution {
public:
    int abc(int i,vector<int>& p){
        if(i==p[i]) return i;
        p[i] = abc(p[i],p);
        return p[i];
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> p(26,0);
        for(int i=0;i<26;i++) p[i]=i;
        for(int i=0;i<s1.length();i++){
            int x = abc(s1[i]-'a',p);
            int y = abc(s2[i]-'a',p);
            p[max(x,y)] = min(x,y);
        }
        for(int i=0;i<baseStr.length();i++){
            baseStr[i]=abc(baseStr[i]-'a',p)+'a';
        }
        return baseStr;
    }
};