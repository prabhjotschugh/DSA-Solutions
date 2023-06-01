class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n=g.size();
        if(g[0][0] || g[n-1][n-1])return -1;
        g[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        int t=0;
        while(q.size()){
            int k=q.size();
            t++;
            while(k--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1 && y==n-1)return t;
                int dx[8]={1,-1,0,0,1,1,-1,-1};
                int dy[8]={0,0,1,-1,1,-1,1,-1};
                for(int i=0;i<8;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<n && g[nx][ny]==0){
                        g[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};