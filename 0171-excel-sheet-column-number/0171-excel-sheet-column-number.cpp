class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size(), val=0;
        for(int i=n-1; i>=0; i--){
            val += pow(26, n-1-i)*(columnTitle[i]-'A'+1);
        }
        return val;
    }
};