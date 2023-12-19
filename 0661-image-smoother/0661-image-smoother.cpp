class Solution {
public:
    vector<int>dx = {-1, -1, 0, +1, +1, +1, 0, -1};
    vector<int>dy = {0, +1, +1, +1, 0, -1, -1, -1};

    bool isValid(int x, int y, int r, int c){
        return (x>=0 && x<r && y>=0 && y<c);
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r = img.size();
        int c = img[0].size();
        vector<vector<int>>ans(r, vector<int>(c, 0));
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                int sum = img[i][j];
                int count = 1;
                for(int k = 0;k<8;k++){
                    if(isValid(i+dx[k], j+dy[k], r, c)){
                        sum+=img[i+dx[k]][j+dy[k]];
                        count++;
                    }
                }
                ans[i][j] = sum/count;
            }
        }
        return ans;
    }
};