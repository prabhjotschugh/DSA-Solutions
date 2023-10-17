class Solution {
public:
    int findNthDigit(int n) {
        int a = 9, d = 1;
        while (n - (long)a * d > 0){
            n -= a * d;
            a *= 10;
            d += 1;
        }
        int num = pow(10, d - 1) + (n - 1) / d;
        return to_string(num)[(n - 1) % d] - '0';
    }
};