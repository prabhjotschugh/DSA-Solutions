class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        priority_queue<int> maxHeap;
        long long sum = 0;
        vector<long long> prefix(n + 1);

        for (int i = 0; i < n; ++i) {
            maxHeap.push(nums[i]);
            sum += nums[i];
        }
        prefix[0] = sum;

        for (int i = n; i < 2 * n; ++i) {
            if (!maxHeap.empty() && nums[i] < maxHeap.top()) {
                sum -= maxHeap.top();
                maxHeap.pop();
                maxHeap.push(nums[i]);
                sum += nums[i];
            }
            prefix[i - n + 1] = sum;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        vector<long long> suffix(n + 1);

        for (int i = 3 * n - 1; i >= 2 * n; --i) {
            minHeap.push(nums[i]);
            sum += nums[i];
        }
        suffix[n] = sum;

        for (int i = 2 * n - 1; i >= n; --i) {
            if (!minHeap.empty() && nums[i] > minHeap.top()) {
                sum -= minHeap.top();
                minHeap.pop();
                minHeap.push(nums[i]);
                sum += nums[i];
            }
            suffix[i - n] = sum;
        }

        long long ans = LLONG_MAX;
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, prefix[i] - suffix[i]);
        }

        return (int) ans;
    }
};