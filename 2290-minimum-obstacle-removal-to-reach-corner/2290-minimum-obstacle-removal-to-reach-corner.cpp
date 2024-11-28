class Solution {
public:
    struct node{
        int a,b,dis;
        bool operator < (const node &other) const{
            return dis>other.dis;

        }
    };
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int mx[4]={0,0,1,-1};
        int my[4]={1,-1,0,0};
        vector<vector<int>>d(n+1,vector<int>(m+1,INT_MAX-123));
        priority_queue<node>pq;
        d[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            node cur=pq.top();
            pq.pop();
            if (cur.dis!=d[cur.a][cur.b]) continue;
            for(int i=0;i<4;i++){
                int newx=cur.a+mx[i];
                int newy=cur.b+my[i];
                if (newx<0 || newy<0 || newx>=n || newy>=m) continue;
                if (d[newx][newy]>d[cur.a][cur.b]+grid[newx][newy]){
                    d[newx][newy]=d[cur.a][cur.b]+grid[newx][newy];
                    pq.push({newx,newy,d[newx][newy]});
                }
            }
        }
        return d[n-1][m-1];
    }
};