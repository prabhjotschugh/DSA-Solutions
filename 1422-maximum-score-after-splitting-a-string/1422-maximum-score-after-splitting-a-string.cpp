class Solution {
public:
    int maxScore(string s) {
        int one_count = count(s.begin(), s.end(),'1');
        int res=0;
        int zero_count= 0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i] == '1'){
                one_count--;
            }else{
                zero_count++;
            }
            res = max(res, zero_count + one_count );
        }
        return res;
    }
};