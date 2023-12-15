class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n  = paths.size();
        unordered_map<string,vector<string>>indegree;
        for(auto ele:paths){
          indegree[ele[0]].push_back(ele[1]);
        }
        for(auto ele:paths){
          if(indegree[ele[0]].size() == 0) return ele[0];
          if(indegree[ele[1]].size() == 0) return ele[1];
        }
        return "null";
    }
};