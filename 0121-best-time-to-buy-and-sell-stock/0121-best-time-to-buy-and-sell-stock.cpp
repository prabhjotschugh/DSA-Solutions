class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = 0;
        int maxProfit = 0;
        
        int n = prices.size();
        for(int i=0;i<n;i++){
            if(prices[low] > prices[i]){
                low = i;
            }
            
            maxProfit = max(maxProfit, prices[i] - prices[low]);
        }
        return maxProfit;
    }
};