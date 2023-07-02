class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int mx=0;
        for(int i=0;i<(1<<requests.size());i++){
            vector<int>a(n,0);
            int t=0;
            for(int j=0;j<requests.size();j++){
                if(i & (1<<j)){
                    t++;
                    a[requests[j][0]]--;
                    a[requests[j][1]]++;
                }
            }
            bool f=true;
            for(int j=0;j<n;j++){
                if(a[j]!=0){
                    f=false;
                    break;
                }
            }
            if(f)mx=max(mx,t);
        }
        return mx;
    }
};