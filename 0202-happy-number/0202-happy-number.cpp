class Solution {
public:
    bool isHappy(int n) {
        while(n!=1&&n!=4){
            int s=0;
            while(n>0){
                int l=n%10;
                s+=l*l;
                n=n/10;
            }
            n=s;
        }
        return n==1;
    }
};