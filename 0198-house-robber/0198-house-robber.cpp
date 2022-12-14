class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prePredecessor = 0;
        int predecessor = 0;
        int current = 0;
        
        for(int i=0;i<n;i++){
            prePredecessor = predecessor;
            predecessor = current;
            current = max(prePredecessor + nums[i] , predecessor);      
        }
        return current;
        
    }
};