class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n = s.size(); 
        vector<pair<int, int>> st(n);
        for(int i = 0; i < n; i++) st[i] = {s[i], i};
        sort(st.begin(), st.end());
        vector<int> dp(n+1, 0); 
        for(int i = n-1; i > -1; i--)
            dp[i] += max(dp[i+1], p[st[i].second] + dp[lower_bound(st.begin() + i, st.end(), make_pair(e[st[i].second], 0)) - st.begin()]);
        return dp[0];
    }
};