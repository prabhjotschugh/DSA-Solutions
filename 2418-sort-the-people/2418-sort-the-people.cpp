class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>>v;
        for(int i=0;i<names.size();i++){
            v.push_back({names[i],heights[i]});
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b){
           return a.second>b.second;
        });
        vector<string>ans;
        for(auto i:v){
            ans.push_back(i.first);
        }
        return ans;
    }
};