#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();           // m = 3n
        int n = m / 3;
        
        /* ---------- 1) prefix: keep n smallest so far ---------- */
        vector<long long> leftMin(m, 0);   // leftMin[i] valid for i >= n-1
        priority_queue<int> maxHeap;       // biggest on top
        long long sum = 0;
        
        for (int i = 0; i < m; ++i) {
            maxHeap.push(nums[i]);
            sum += nums[i];
            
            if ((int)maxHeap.size() > n) { // remove largest → keep n smallest
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            
            if (i >= n - 1)
                leftMin[i] = sum;          // current best prefix sum of n elements
        }
        
        /* ---------- 2) suffix: keep n largest so far ---------- */
        vector<long long> rightMax(m, 0);  // rightMax[i] valid for i <= 2n
        priority_queue<int, vector<int>, greater<int>> minHeap;  // smallest on top
        sum = 0;
        
        for (int i = m - 1; i >= 0; --i) {
            minHeap.push(nums[i]);
            sum += nums[i];
            
            if ((int)minHeap.size() > n) { // remove smallest → keep n largest
                sum -= minHeap.top();
                minHeap.pop();
            }
            
            if (i <= 2 * n)
                rightMax[i] = sum;         // current best suffix sum of n elements
        }
        
        /* ---------- 3) try every border between the two parts ---------- */
        long long answer = LLONG_MAX;
        for (int border = n - 1; border <= 2 * n - 1; ++border) {
            long long diff = leftMin[border] - rightMax[border + 1];
            answer = min(answer, diff);
        }
        return answer;
    }
};