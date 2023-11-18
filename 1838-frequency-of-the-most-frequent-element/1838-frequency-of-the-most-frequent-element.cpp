class Solution {
public:
    bool check(int mid,vector<int> &nums,int k,int n)
    {
        long long int i=0,j=0;
        long long int sum=0;
        while(j<n)
        {
            sum+=nums[j];
            while((j-i+1)>mid)
            {
                sum-=nums[i];
                i++;
            }
            if((j-i+1)==mid)
            {
                if(((j-i+1)*nums[j] - sum) <= k)
                    return 1;
            }
            j++;
        }
        return 0;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low=1,high=n;
        int ans=1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,nums,k,n))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};