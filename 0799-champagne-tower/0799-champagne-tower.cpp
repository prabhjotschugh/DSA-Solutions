class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured==0) return 0;
        vector<double> row(1, poured);
        for(int i=0; i<query_row; i++){
            vector<double> next(i+2, 0);
            for(int j=0; j<=i; j++){
                if (row[j]<=1) continue;
                double excess=(row[j]-1)/2.0;
                next[j]+= excess;
                next[j+1]+= excess;
            }
            row=next;
        }
        return min(1.0, row[query_glass]); 
    }
};