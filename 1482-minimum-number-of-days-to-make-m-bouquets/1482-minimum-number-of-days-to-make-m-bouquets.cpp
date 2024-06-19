class Solution {
public:
    bool canHappen(int days, vector<int>& bloomDay, int m, int k) {
        int K = 0, bouquets = 0;
        for(int i=0;i<bloomDay.size();i++) {
            if(bloomDay[i] <= days) {
                K++;
                if(K == k) {
                    bouquets++;
                    K = 0;
                }
            }
            else K = 0;
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = 1, n = bloomDay.size(), ans = -1;
        if(m > (n / k)) return -1;
        for(int i = 0;i<bloomDay.size();i++) high = max(high, bloomDay[i]);

        while(low <= high) {
            int mid = low + (high - low)/2;
            if(canHappen(mid, bloomDay, m, k)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }

        return ans;
    }

};