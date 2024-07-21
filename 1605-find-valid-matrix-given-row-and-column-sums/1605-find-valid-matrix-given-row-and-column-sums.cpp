class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size(),i=0;
        int m=colSum.size(),j=0;
        vector<vector<int>>ans(n,vector<int>(m,0));
        while(i<n && j<m){
           if(rowSum[i]<colSum[j]){
             ans[i][j]=rowSum[i];
             colSum[j]-=rowSum[i];
             rowSum[i]=0;
           }else{
             ans[i][j]=colSum[j];
             rowSum[i]-=colSum[j];
             colSum[j]=0;
           }
           if(rowSum[i]==0) i++;
           if(colSum[j]==0) j++;
        }
        return ans;
    }
};