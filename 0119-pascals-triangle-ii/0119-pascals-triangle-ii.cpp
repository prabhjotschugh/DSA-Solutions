class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        long long val = 1;
        for (int i = 0; i <= rowIndex; i++) {
            result[i] = val;
            val = val * (rowIndex - i) / (i + 1);
        }
        return result;
    }
};