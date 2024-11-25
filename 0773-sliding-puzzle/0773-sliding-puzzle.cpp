class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        int m = board.size();
        int n = board[0].size();
        string start = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start += to_string(board[i][j]);
            }
        }
        vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        unordered_set<string> visited;
        queue<string> q;
        visited.insert(start);
        q.push(start);
        int count = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();

                if (current == target) {
                    return count;
                }

                int zeroIndex = current.find('0');
                for (int dir : directions[zeroIndex]) {
                    string next = current;
                    swap(next[zeroIndex], next[dir]);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            count++;
        }

        return -1;
    }
};