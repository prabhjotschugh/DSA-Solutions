class Solution {
public:
    int totalMoney(int n) {
        int div = n/7;
        int rem = n%7;
        int start = 1;
        int sum = 0;
        for(int i=0; i<div; i++) {
            int end = start+6;
            int tmp = ((start+end)*7)/2;
            sum += tmp;
            start++;
        }
        for(int i=0; i<rem; i++) {
            sum+=start++;
        }
        return sum;
    }
};