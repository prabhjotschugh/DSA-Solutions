class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int len=0;
        for(int x: arr){
            len=(x&1)?len+1:0;
            if (len==3) return 1;
        }
        return 0;
    }
};