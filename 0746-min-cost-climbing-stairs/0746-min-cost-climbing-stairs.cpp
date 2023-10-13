class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<vector<int>> vec(3, vector<int>(cost.size()));
        vec[0][0] = 0, vec[1][0] = cost[0], vec[2][0] = 0;
        for(int i = 1; i < cost.size(); i++){
            vec[0][i] = vec[1][i-1]; 
            vec[1][i] = vec[2][i-1] + cost[i]; 
            vec[2][i] = min(vec[0][i], vec[1][i]);
        }
        return vec[2][cost.size() - 1];
    }
};