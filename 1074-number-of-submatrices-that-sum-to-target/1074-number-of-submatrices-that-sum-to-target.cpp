class Solution {
public:
    int helper(vector<int> &nums, int k){
        int frequency = 0, ans = 0; ; 
        map<int, int> mapping; 
        for(int i = 0; i < nums.size(); ++i){
            ans += nums[i]; 
            if(ans == k){
                frequency++; 
            }
            if(mapping.find(ans - k) != mapping.end()){ 
                frequency += mapping[ans - k];
            }
            mapping[ans]++; 
        }
        return frequency;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        for(int i = 0; i < matrix.size(); ++i){
            vector<int> result(matrix[0].size(), 0);
            for(int j = i; j < matrix.size(); ++j){ 
                for(int k = 0; k < matrix[0].size(); ++k){ 
                    result[k] += matrix[j][k];
                }
                count += helper(result, target);
            }
        }
        return count;
    }
};