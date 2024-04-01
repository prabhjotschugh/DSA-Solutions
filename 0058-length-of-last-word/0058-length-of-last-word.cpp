class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), length = 0;
        for(int i=n-1;i>=0;i--){
            if(length>0 && s[i] == ' ')break;
            if(s[i] != ' ')length++;
        }
        return length;
    }
};