class Solution {
public:
    queue<pair<int,int>> q;
    int d[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    bool check(vector<vector<int>>& nums,int i,int j){
        if(i<0||i>=nums.size()||j<0||j>=nums[0].size()) return 0;
        return 1;
    }
    void dfs(vector<vector<int>>& nums,vector<vector<int>>& vis,int i,int j){
        if(!check(nums,i,j) || vis[i][j]) return;
        if(nums[i][j]==0){
            vis[i][j]=1; q.push({i,j});
            return;
        }
        vis[i][j]=1;
        dfs(nums,vis,i+1,j); dfs(nums,vis,i-1,j);
        dfs(nums,vis,i,j+1); dfs(nums,vis,i,j-1);
    }
    int shortestBridge(vector<vector<int>>& nums) {
        vector<vector<int>> vis(nums.size(),vector<int>(nums[0].size(),0));
        bool st = 1;
        for(int i = 0; i<nums.size();++i){
            for(int j = 0; j<nums[0].size() && st;++j){
                if(nums[i][j]){
                    dfs(nums,vis,i,j); st=0;
                    break;
                }
            }
        }
        int l = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto[i,j] = q.front(); q.pop();
                if(nums[i][j]==1) return l;
                for(int k = 0; k<4;++k){
                    int x=i+d[k][0],y=j+d[k][1];
                    if(check(nums,x,y) && !vis[x][y]){
                        vis[x][y]=1; q.push({x,y});
                    }
                }
            }
            ++l;
        }
        return 0;
    }
};