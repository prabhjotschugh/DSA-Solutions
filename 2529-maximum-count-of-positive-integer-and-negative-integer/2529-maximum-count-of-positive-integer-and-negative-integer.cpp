class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg = 0, p = 0, negl = 0, posf = 0, posl = 0;

        if (nums[0] == 0 && nums[n - 1] == 0)
            return 0;

        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] < 0) {
                negl = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        i = 0;
        j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] > 0) {
                posf = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        if (nums[n - 1] > 0)
            posl = n - 1;

        p = posl - posf + 1;
        neg = negl + 1;

        return max(p, neg);
    }
};