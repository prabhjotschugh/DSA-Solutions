class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2-ax1)*(ay2-ay1);
        int area2 = (bx2-bx1)*(by2-by1);
        
        int total = area1 + area2; 
        
        if(ay1>=by2 || by1>=ay2 || bx1>=ax2 || ax1>=bx2){
            return total;
        }
        else{
            int len = min(ax2, bx2) - max(bx1, ax1);
            int br = min(ay2, by2) - max(ay1, by1);
            int dup = len*br;
            return total - dup;
        }
    }
};