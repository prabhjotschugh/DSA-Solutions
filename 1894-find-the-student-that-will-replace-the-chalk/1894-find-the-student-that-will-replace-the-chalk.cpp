class Solution {
public:
    int chalkReplacer(vector<int>& c, int k) {
        long n = c.size(), sum, left;
        vector<long> pref(n); 
        pref[0] = c[0];
        for(int i = 1;i<n;i++) 
            pref[i] = pref[i-1] + c[i];
        
        sum = pref[n-1];
        if(k%sum == 0) 
            return 0;
        
        left = k - (k/sum)*sum;
        return upper_bound(pref.begin(), pref.end(), left) - pref.begin();
    }
};