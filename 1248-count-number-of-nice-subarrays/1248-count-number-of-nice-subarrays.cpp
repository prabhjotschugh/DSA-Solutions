class Solution {
public:
    int n;
    int niceLessEqualK(vector<int>& nums, int k){
        int odds=0, cnt=0;
        for(int l=0, r=0; r<n; r++){
            int x=nums[r];
            odds+=(x&1);
            while(odds>k){
                int y=nums[l];
                odds-=(y&1);
                l++;
            }
            cnt+=(r-l+1); 
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        n = nums.size();
        return niceLessEqualK(nums, k)-niceLessEqualK(nums, k-1);
    }
};