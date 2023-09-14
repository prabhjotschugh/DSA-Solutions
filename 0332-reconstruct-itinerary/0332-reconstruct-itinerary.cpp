class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>f;
    vector<string>ans;

    void dfs(string dept){
        while(!f[dept].empty()){
            string to=f[dept].top();
            f[dept].pop();
            dfs(to);
        }
        ans.push_back(dept);
    }

    void flight(vector<vector<string>> &tickets){
        for(auto &it: tickets){
            string from=it[0];
            string to=it[1];
            f[from].push(to);
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        flight(tickets);
        dfs("JFK");
        reverse(ans.begin(),ans.end());

        return ans;
    }
};