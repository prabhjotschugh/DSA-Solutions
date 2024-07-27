class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> costMatrix(26, vector<int>(26, INT_MAX));
        for(int i = 0 ; i < 26 ; i++) costMatrix[i][i] = 0;
        int szA = original.size();
        for(int i = 0 ; i < szA ; i++){
            costMatrix[original[i] - 'a'][changed[i] - 'a'] = min(costMatrix[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        for(int k = 0 ; k < 26 ; k++){
            for(int i = 0 ; i < 26 ; i++){
                for(int j = 0 ; j < 26 ; j++){
                    if(costMatrix[i][k] != INT_MAX && costMatrix[k][j] != INT_MAX)
                    costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][k] + costMatrix[k][j]);
                }
            }
        }

        long long costRes = 0;
        int szB = source.size();
        for(int i = 0 ; i < szB ; i++){
            if(costMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1;
            costRes += costMatrix[source[i] - 'a'][target[i] - 'a'];
        }
        return costRes;
    }
};