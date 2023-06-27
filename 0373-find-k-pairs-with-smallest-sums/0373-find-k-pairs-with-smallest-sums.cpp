class Solution{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int sum = nums1[i] + nums2[j];
                if(maxHeap.size() < k){
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                }else if(sum < maxHeap.top().first){
                    maxHeap.pop();
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                }else{
                    break;
                }
            }
        }

        vector<vector<int>> ans;
        while(!maxHeap.empty()){
            ans.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};