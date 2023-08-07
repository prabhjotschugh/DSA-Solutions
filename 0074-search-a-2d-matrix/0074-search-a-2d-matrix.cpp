class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int l=0, r=n*m-1;
        
        while(l <= r){
            int mid = l+(r-l)/2;
            int x = matrix[mid/m][mid%m];
            
            if(x > target){
                r = mid-1;
            }else if(x < target){
                l = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
};