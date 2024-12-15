class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(int i=0;i<classes.size();i++){
             int var1 = classes[i][0] , var2 = classes[i][1];
            double diff = (double)(var1+1)/(var2+1) - (double)(var1)/(var2);
              pq.push({diff,{var1,var2}});
        }
        
        while(extraStudents!=0){
            int var1 = pq.top().second.first , var2 = pq.top().second.second;
            var1++;
            var2++;
            double newdiff = (double)(var1+1)/(var2+1) - (double)(var1)/(var2);
            pq.pop();
             pq.push({newdiff,{var1,var2}});
            extraStudents--;
            
        }
        double ans = 0;
        while(!pq.empty()){
            ans += (double)(pq.top().second.first) /(pq.top().second.second);
            pq.pop();
        }
         
        return ans/classes.size();
    }
};