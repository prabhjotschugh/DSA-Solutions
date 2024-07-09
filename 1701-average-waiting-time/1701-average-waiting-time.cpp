class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double total=c[0][0];
        double wait=0;
        for(int i=0;i<c.size();i++){
            if(c[i][0]<total){
                total+=c[i][1];
                wait+=(total-c[i][0]);
            }else{
                total=c[i][0]+c[i][1];
                wait+=c[i][1];
            }
            
        }
        return wait/c.size();
    }
};