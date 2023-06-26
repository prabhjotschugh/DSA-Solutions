class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = 0;
        int high = 0;
        int maxProfit = 0;
        
        int n = prices.size();
        for(int i=1;i<n;i++){
            if(prices[i] >= prices[i-1]){
                high++;
            }else{
                maxProfit += prices[high] - prices[low];
                high = i;
                low = i;
            }
        }
        maxProfit += prices[high] - prices[low];
        
        return maxProfit;
    }
};