class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>a=arr;
        sort(a.begin(),a.end());
        unordered_map<int,int>mp;
        int i=0,n=arr.size(),rank=1;
        while(i<n){
            if(i==0){}
            else if(a[i]==a[i-1]){}
            else rank++;
            mp[a[i]]=rank;
            i++;
        }
        for(auto &x:arr){
            x=mp[x];
        }
        return arr;
    }
};