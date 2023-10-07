class Solution {
public:
    int dp[1006][1006];
    int solve(int i, int k, int sz,int ht, vector<vector<int>>& books){
        if(i == books.size()) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        if(books[i][0] <= k){
            int x;
            if(books[i][1] > ht){
                x = (books[i][1] - ht)  + solve(i+1,k-books[i][0],sz,books[i][1],books);
            }
            else x = solve(i+1,k-books[i][0],sz,ht,books);
            return dp[i][k] = min(x, books[i][1] + solve(i+1,sz-books[i][0],sz,books[i][1],books) );
        }
        return dp[i][k] = books[i][1] + solve(i+1,sz-books[i][0],sz,books[i][1],books);
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        return books[0][1] + solve(1,shelfWidth-books[0][0],shelfWidth,books[0][1],books);
    }
};