class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int n = colors.size();
        for(int i = 1; i < n; i++)
        {
            if(colors[i] == colors[i - 1])
            {
                time += min(neededTime[i], neededTime[i - 1]); 
                neededTime[i] = max(neededTime[i], neededTime[i - 1]); 
            }     
        }
        
        return time;
    }
};