class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i=1;
        int w=1;
        for(int i=1;i<=area/i;i++){
            if(area%i!=0){continue;}
            if(i>w){w=i;}
        }
        i=i-1;
        return {area/w,w};
    }
};