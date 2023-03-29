class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<int>v=satisfaction;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int sum=0,ans=0;
        for(int i=0;i<v.size();i++){
            if(sum+v[i]>0){
                ans+=sum+v[i];
                sum+=v[i];
            }
        }
        return ans;
    }
};