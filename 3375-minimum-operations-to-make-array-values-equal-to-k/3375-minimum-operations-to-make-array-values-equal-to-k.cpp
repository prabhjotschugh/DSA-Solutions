class Solution {
public:
    static int minOperations(vector<int>& nums, int k) {
        bitset<101> hasX=0;
        int xMin=101;
        [[unroll]]
        for(int x: nums){
            hasX[x]=1;
            xMin=min(x, xMin);
        }
        if (xMin<k) return -1;
        return (xMin==k)?hasX.count()-1:hasX.count();
    }
};
