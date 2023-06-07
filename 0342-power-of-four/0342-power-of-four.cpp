class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return 0;
        while(n%4==0){
            n=n/4;
        }
        return (n==1) ? 1 : 0;
    }
};