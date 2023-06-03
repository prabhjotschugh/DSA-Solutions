class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas=0, totalCost=0, current=0;
        int ans = 0;
        for(int i=0;i<n;i++){
            totalGas += gas[i];
            totalCost += cost[i];
            
            current += gas[i]-cost[i];
            if(current < 0){
                ans = i+1;
                current = 0;
            }
        }
        if(totalCost > totalGas) return -1;
        return ans;
    }
};