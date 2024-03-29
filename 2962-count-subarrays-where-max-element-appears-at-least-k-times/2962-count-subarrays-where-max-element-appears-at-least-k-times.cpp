class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxe=*max_element(nums.begin(), nums.end());
        long long ans=0;
        int count=0; 
        int i=0, j=0;
        while(j<n){
            count += (nums[j] == maxe);
            while(i<=j && count>=k){
                ans += (n-j);
                count -= (nums[i] == maxe); 
                i++;
            }
            j++;
        }
        
        return ans;
    }
};