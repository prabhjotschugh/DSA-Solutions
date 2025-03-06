class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long sum_n = (long long)n * n * (n * n + 1) / 2;
        long long sum_squares = (long long)n * n * (n * n + 1) * (2 * n * n + 1) / 6;
        long long grid_sum = 0, grid_sum_squares = 0;

        for (const auto& row : grid) {
            for (int num : row) {
                grid_sum += num;
                grid_sum_squares += (long long)num * num;
            }
        }

        long long diff_sum = grid_sum - sum_n;
        long long diff_sum_squares = grid_sum_squares - sum_squares; 
        long long sum_ab = diff_sum_squares / diff_sum;

        int a = (diff_sum + sum_ab) / 2;
        int b = (sum_ab - diff_sum) / 2; 

        return {a, b}; 
    }
};
