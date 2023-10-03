class Solution {
public:
    vector<string> splitByDelimeter(string str) {
        stringstream ss(str);
        string s;
        vector<string> res;
        while(getline(ss, s, '#')) {
            res.push_back(s);
        }
        return res;
    }
    
    bool matchStrings(const string &A, const string &B) {
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == '.') continue;
            if (A[i] != B[i]) return false;
        }
        return true;
    }
    
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        string rev = word;
        reverse(begin(rev), end(rev));
        int n = board.size();
        int m = board[0].size();
        string str;
        for (int i = 0; i < n; ++i) {
            str = "";
            for (int j = 0; j < m; ++j) {
                str += (board[i][j] == ' '? '.': board[i][j]);
            }
            auto res = splitByDelimeter(str);
            for (const string &x: res) {
                if (x.size() != word.size()) continue;
                if (matchStrings(x, word) || matchStrings(x, rev)) return true;
            }
        }
        
        for (int j = 0; j < m; ++j) {
            str = "";
            for (int i = 0; i < n; ++i) {
                str += (board[i][j] == ' '? '.': board[i][j]);
            }
            auto res = splitByDelimeter(str);
            for (const string &x: res) {
                if (x.size() != word.size()) continue;
                if (matchStrings(x, word) || matchStrings(x, rev)) return true;
            }
        }
        return false;
    }
};