#define ll long long int

class Solution {
public:
    bool valid(ll maxi, int n, vector<int>& qnt){
        int cnt = 0;
        for(auto it: qnt){
            if(it % maxi == 0) cnt += it / maxi;
            else cnt += it / maxi + 1;
            if(cnt > n) return false;
        }
        return cnt <= n;
    }
    int minimizedMaximum(int n, vector<int>& qnt) {
        ll l = 1, r = *max_element(qnt.begin(), qnt.end());
        ll ans = r;
        while(l<=r){
            ll mid = l+(r-l)/2;
            if(valid(mid,n,qnt)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};