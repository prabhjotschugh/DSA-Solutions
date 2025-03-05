#define ll long long int
class Solution {
public:
    long long coloredCells(long long n) {
        ll squares_n = n*n;
        ll squares_n_minus1 = (n-1)*(n-1);
        
        ll ans = squares_n + squares_n_minus1;
        return ans;
    }
};