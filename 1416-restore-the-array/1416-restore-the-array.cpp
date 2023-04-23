class Solution {
public:
    int numberOfArrays(string s, int k) {
        const long mod = 1e9+7;
        const int n = s.size();
        vector<long> dp(n+1, 0);
        dp[0] = 1;
        deque<string> preK;
        for(int i=0;i<n;i++){
            for(auto& t:preK){
                t+=s[i];
            }
            preK.push_back(string(1,s[i]));
            while(!preK.empty()) {
                auto& t = preK.front();
                if(stoll(t) > k || t[0] == '0') preK.pop_front();
                else break;
            }
            for(int j=0;j<preK.size();j++){
                if(preK[j][0] == '0') continue;
                dp[i+1] += dp[i-preK.size()+1+j];    
            }            
            dp[i+1] %= mod;
        }
        return dp[n];
    }
};