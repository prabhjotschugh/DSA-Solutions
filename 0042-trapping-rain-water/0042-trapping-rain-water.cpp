class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> maxiLeft(n, 0);
        vector<int> maxiRight(n, 0);
        
        maxiLeft[0] = height[0];
        for(int i=1;i<n;i++){
            maxiLeft[i] = max(maxiLeft[i-1], height[i]);
        }
        
        maxiRight[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            maxiRight[i] = max(maxiRight[i+1], height[i]);
        }
        
        vector<int> water(n, 0);
        for(int i=0;i<n;i++){
            water[i] = min(maxiLeft[i], maxiRight[i]) - height[i];
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans += water[i];
        }
        
        return ans;
    }
};