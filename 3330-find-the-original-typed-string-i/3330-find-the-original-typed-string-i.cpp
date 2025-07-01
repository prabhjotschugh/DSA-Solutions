class Solution {
public:
    static int possibleStringCount(string& word) {
        int f=1, cnt=1;
        char prev='X';
        for(char c: word){
            if (c!=prev) {
                cnt+=(f>1)?(f-1):0;
                f=1;
            }
            else f++;
            prev=c;
        }
        cnt+=(f>1)?(f-1):0;
        return cnt;
    }
};