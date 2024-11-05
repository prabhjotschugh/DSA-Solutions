class Solution {
public:
    int minChanges(string s) {
        int counter = 0;
        for(int i=0; i<s.length(); i+=2){
            counter+=(s[i]!=s[i+1]);
        }
        return counter;
    }
};