class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int,int>> pq1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
        for(int i=0;i<arrays.size();i++){
            pq2.push({arrays[i][0],i});
            pq1.push({arrays[i][arrays[i].size()-1],i});
        }
        if(pq1.top().second == pq2.top().second){
            int maxi = pq1.top().first,mini=pq2.top().first;
            pq1.pop(),pq2.pop();
            int ans1 = maxi - pq2.top().first, ans2 = pq1.top().first - mini;
            return max(ans1,ans2);
        }
        return pq1.top().first - pq2.top().first;
    }
};