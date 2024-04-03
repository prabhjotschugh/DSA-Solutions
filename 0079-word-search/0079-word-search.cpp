class Solution {
    int dr1[4]={1,-1,0,0};
    int dr2[4]={0,0,1,-1};
public:
    bool solve(vector<vector<char>>& board,int& row,int& col,int i,int j,string& word,int ind,int n){
           if(ind==n-1 && word[ind]==board[i][j])return true;
           for(int d=0;d<4;d++){
             int x=i+dr1[d],y=j+dr2[d];
             if(x>=0&&x<row&&y>=0&&y<col && board[x][y]!='.' && board[x][y]==word[ind]){
                char ch=board[x][y];
                board[x][y]='.';
                if(ind==n-1)return true;
                if(solve(board,row,col,x,y,word,ind+1,n)==true)return true;
                board[x][y]=ch; 
             }
           }
           return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(),col=board[0].size(),n=word.size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(solve(board,row,col,i,j,word,0,n)==true)return true;
            }
        }
        return false;
    }
};