class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int total=tickets[k];

        for(int i=0;i<k;i++){
            total+=min(tickets[k],tickets[i]);
        }
        for(int i=k+1;i<n;i++){
            total+=min(tickets[k]-1,tickets[i]);
        }
        return total;
    }
};