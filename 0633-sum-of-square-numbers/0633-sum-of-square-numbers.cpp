#define ll long long int
class Solution {
public:
    bool judgeSquareSum(int c) {
        ll left = 0, right = static_cast<ll>(sqrt(c));
        while(left <= right) {
            if(left * left + right * right == c) return true;
            else if(left * left + right * right > c) right--;
            else left++;
        }
        return false;
    }
};