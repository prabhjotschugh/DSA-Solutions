class Solution {
public:
    bool isUgly(int n) {
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        while(n>1){
            if(n%2==0) n/=2;
            else if(n%3==0) n/=3;
            else if(n%5==0) n/=5;
            else return 0;
        }
        return 1;
    }
};