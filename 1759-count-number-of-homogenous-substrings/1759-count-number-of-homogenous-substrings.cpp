class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        long long int ans = 0;
        int n = s.size();
        int i = 0;
        char start = s[i];
        long long int ct = 0;
        while(i <= n){
        
            while(i<n && s[i] == start){
                ct++;
                i++;
            }
            ans += (ct%mod*(ct+1)%mod)%mod/2;
            if(i < n)
            start = s[i];
            i++;
            ct = 1;
        }

        return ans;
    }
};