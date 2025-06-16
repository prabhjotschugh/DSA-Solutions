class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int xMin=nums[0], n=nums.size();
        int maxD=-1;
        for(int i=1; i<n; i++){
            int x=nums[i];
            if (x<=xMin)
                xMin=x;
            else maxD=max(maxD, x-xMin); 
        }
        return maxD;
    }
};