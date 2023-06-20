class Solution {
public:
    vector<int> getAverages(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>ans(n);
        
        vector<long long>pref(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + arr[i];
        
        for (int i = 0; i < n; i++){
            int lcnt = i;
            int rcnt = n - i - 1;
            if (lcnt >= k and rcnt >= k)
            {
                long long lsum = 0;
                long long rsum = pref[i + k];
                
                if (i - k > 0)
                    lsum = pref[i - k - 1];
                    
                ans[i] = (rsum - lsum) / (2*k + 1);
            }
            else
                ans[i] = -1;
        }
        return ans;
    }
};