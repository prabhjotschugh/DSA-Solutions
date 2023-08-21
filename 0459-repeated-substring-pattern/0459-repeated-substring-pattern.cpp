class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s; 
        for(int i=0; i<s.size()-1; i++){ 
            char c = t[0];  
            t.erase(0,1);
            t.push_back(c);
            if(t==s) { 
                return true; 
            }
        }
        return false;
    }
};