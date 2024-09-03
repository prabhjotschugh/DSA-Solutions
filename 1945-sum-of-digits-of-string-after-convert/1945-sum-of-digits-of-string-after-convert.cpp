class Solution {
public:
    int getLucky(string s, int k) {
        string res;
        for(auto &x : s) {
            res += to_string(x - 'a' + 1);
        }   
        int ans = 0;
        while(k>0) {
            for(auto &i : res) {
                ans += (i - '0');
            }
            res = to_string(ans);
            k--;
            if(k == 0) break;
            ans = 0;
        }
        return ans;
    }
};