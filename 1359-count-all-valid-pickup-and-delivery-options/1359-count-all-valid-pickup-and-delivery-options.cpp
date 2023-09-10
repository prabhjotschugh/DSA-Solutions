class Solution {
public:
    const int mod=1e9+7;
    int countOrders(int n) {
        long long num=1;
        for(long long i=1; i<n; i++){
            num=(num*(i+1)*(2*i+1)%mod);
        }
        return num;
    }
};