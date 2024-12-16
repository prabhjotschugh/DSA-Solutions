typedef pair<long, int> pi;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int mod = 1e9+7;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        int n = nums.size();
        for(int i=0;i<n;i++)
            pq.push({nums[i], i});
        
        while(k--){
            auto top = pq.top(); pq.pop();
            int val = (top.first * multiplier) % mod;
            int idx = top.second;
            pq.push({val, idx});
        }

        vector<int>ans(n);
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int val = top.first;
            int idx = top.second;
            ans[idx] = val;
        }
        return ans;
    }
};