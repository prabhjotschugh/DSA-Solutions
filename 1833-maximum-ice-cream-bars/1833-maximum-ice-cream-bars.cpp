class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        if(costs[0]>coins){
            return 0;
        }
        int counter=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins){
                counter++;
                coins-=costs[i];
            }else{
                break;
            }
        }
        return counter;
    }
};