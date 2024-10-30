class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 0);
        vector<int> lds(n, 0);

        for (int i=0; i<n; i++) {
            int temp = 0;
            for (int x=0; x<=i; x++) {
                if (nums[x] < nums[i]) {
                    temp = max(temp, lis[x]);
                }
            }
            lis[i] = temp+1;
        }
        for (int i=n-1; i>=0; i--) {
            int temp = 0;
            for (int x=n-1; x>=i; x--) {
                if (nums[x] < nums[i]) {
                    temp = max(temp, lds[x]);
                }
            }
            lds[i] = temp+1;
        }
        int maxLen = 0;
        for (int i=1; i<n-1; i++) {
            if (lds[i] != 1 && lis[i] != 1) {
                maxLen = max(maxLen, lis[i] + lds[i]-1);
            }
        }
        
        return n-maxLen;
    }
};