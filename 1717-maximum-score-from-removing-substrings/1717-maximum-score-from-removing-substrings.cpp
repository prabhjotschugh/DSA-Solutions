class Solution {
public:
    void clear(stack<pair<char, int>>& st){
        while(!st.empty()) st.pop();
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;
        int n = s.length();
        
        if (y > x) {
            stack<pair<char, int>> st;
            vector<int> vis(n);

            for (int i = 0; i < s.length(); i++) {
                if (!st.empty() && st.top().first == 'b' && s[i] == 'a') {
                    vis[i] = 1;
                    vis[st.top().second] = 1;
                    st.pop();
                    ans += y;
                } else {
                    st.push({s[i], i});
                }
            }

            clear(st);

            for (int i = 0; i < n; i++) {
                if (vis[i] == 1) continue;

                if (!st.empty() && st.top().first == 'a' && s[i] == 'b') {
                    st.pop();
                    ans += x;
                } else {
                    st.push({s[i], i});
                }
            }
        } else {
            stack<pair<char, int>> st;
            vector<int> vis(n);

            for (int i = 0; i < s.length(); i++) {
                if (!st.empty() && st.top().first == 'a' && s[i] == 'b') {
                    vis[i] = 1;
                    vis[st.top().second] = 1;
                    st.pop();
                    ans += x;
                } else {
                    st.push({s[i], i});
                }
            }

            clear(st);

            for (int i = 0; i < n; i++) {
                if (vis[i] == 1) continue;

                if (!st.empty() && st.top().first == 'b' && s[i] == 'a') {
                    st.pop();
                    ans += y;
                } else {
                    st.push({s[i], i});
                }
            }
        }

        return ans;
    }
};