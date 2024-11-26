class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for(auto it: edges){
            indegree[it[1]]++;
        }
        int cnt=0;
        int ind = -1;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                cnt++;
                ind = i;
            }
        }
        return (cnt == 1) ? ind : -1;  
    }
};