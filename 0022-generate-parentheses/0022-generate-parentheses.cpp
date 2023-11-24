class Solution {
public:
    void generate(int open, int close, string output, vector<string>& ans){
        if (open == 0 && close == 0){
            ans.push_back(output);
            return;
        }
        if (open > 0){
            output.push_back('(');
            generate(open-1, close, output, ans);
            output.pop_back();
        }
		if (close > open){
            output.push_back(')');
            generate(open, close-1, output, ans);
            output.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        string output = "";
        vector<string> ans;
        generate(n, n, output, ans);
        return ans;
    }
};