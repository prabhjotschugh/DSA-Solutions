class Solution {
public:
    int minimizeMax(vector<int>& v, int p) {
        int n = v.size();
        sort(v.begin(), v.end()); 
        
        int lo = -1, hi = 1e9 + 7;
        while (lo < hi - 1) {
            int mid = lo + (hi - lo) / 2;
            int a = 0; 
            for (int i = 1; i < n; i++) {
                if (v[i] - v[i - 1] <= mid) {
                    a++;
                    i++; 
                }
            }
            if (a >= p) hi = mid;
            else lo = mid;
        }
        return hi;
    }
};