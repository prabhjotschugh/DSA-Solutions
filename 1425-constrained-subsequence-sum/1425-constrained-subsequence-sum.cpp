class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            int prevMaxTaken = 0;
            if(!pq.empty()) prevMaxTaken = pq.top().first;
            int temp = max(nums[i] , nums[i] + prevMaxTaken);
            pq.push({temp , i});
            ans = max(ans , temp);
            while(pq.top().second<=i-k){
                pq.pop();
            }
        }
        return ans;
    }
};