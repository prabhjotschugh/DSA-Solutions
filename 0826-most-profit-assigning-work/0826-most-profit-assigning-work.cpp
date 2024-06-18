class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int i,j=0,k=0,n=p.size();
        vector<pair<int,int>>v;
        for(i=0;i<n;i++){
            v.push_back({d[i],p[i]});
        }
        sort(v.begin(),v.end());
        j=0;
        priority_queue<int>pq;
        sort(w.begin(),w.end());
        for(i=0;i<w.size();i++){
           while(j<n){
             if(v[j].first>w[i]){
                break;
             }
             pq.push(v[j].second);
             j++;
           }
           if(j>0)k+=pq.top();
        }
        return k;
    }
};