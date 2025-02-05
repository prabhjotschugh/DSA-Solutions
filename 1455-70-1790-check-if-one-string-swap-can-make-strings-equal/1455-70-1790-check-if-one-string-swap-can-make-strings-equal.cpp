class Solution {
public:
    bool areAlmostEqual(string& s1, string& s2) {
        const int n=s1.size();
        int cntD=0, i;
        array<char, 2> D={0};
        for(i=0; i<n && cntD<=2; i++){
            char x=s1[i], y=s2[i];
            if (x!=y){
                cntD++;
                if (cntD>2 ||(cntD==2 && (D[0]!=y || D[1]!=x )))
                    return 0;
                D={x, y};
            }
        }
        return cntD==0 || cntD==2;
    }
};