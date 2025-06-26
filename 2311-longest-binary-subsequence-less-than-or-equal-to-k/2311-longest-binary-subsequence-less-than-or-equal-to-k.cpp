class Solution {
public:
    int longestSubsequence(string& s, int k) {
        const int n=s.size();
        const int wz=33-countl_zero((unsigned)k);
        vector<int> suff(n+1);
        long long x=0;
        for(int l=n-1, r=n-1; l>=0; l--){
            if(s[l]=='1') x+=(1LL<<(r-l));
            if (r-l>=wz) r--;
            suff[l]=suff[l+1]+(x<=k);
            if (x>k){
                x>>=1;
                r--;
            }
        }
        int ans=0, cnt0=0;
        for(int i=0; i<n; i++){
            ans=max(ans, cnt0+suff[i]);
            cnt0+=(s[i]=='0');
        }
        return ans;
    }
};