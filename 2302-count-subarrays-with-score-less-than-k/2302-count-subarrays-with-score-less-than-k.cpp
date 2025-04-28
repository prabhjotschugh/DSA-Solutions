class Solution {
public:
    static long long countSubarrays(vector<int>& nums, long long k) {
        if (k<=1) return 0; // edge case
        long long score=0, sum=0, cnt=0;
        int n=nums.size(), l=0;
        for(int r=0; r<n; r++){
            sum+=nums[r];
            score=sum*(r-l+1);
            while(score>=k){
                sum-=nums[l++];
                score=sum*(r-l+1);
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
};
