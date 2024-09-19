class Solution {
public:
    unordered_map<string,vector<int>> m;
    vector<int> solveTopDown(string s){
        vector<int> ans;
        if(m.find(s) != m.end()) return m[s];

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '+' or s[i] == '*' or s[i] == '-'){
                vector<int> left = solveTopDown(s.substr(0,i));
                vector<int> right = solveTopDown(s.substr(i+1));

                for(auto x : left){
                    for(auto y : right){
                        if(s[i] == '+') 
                            ans.push_back(x + y);
                        else if(s[i] == '-') 
                            ans.push_back(x - y);
                        else 
                            ans.push_back(x * y);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(s));
        return m[s] = ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solveTopDown(expression);
    }
};