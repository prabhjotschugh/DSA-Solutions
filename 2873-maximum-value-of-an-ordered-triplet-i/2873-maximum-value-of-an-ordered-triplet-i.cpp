class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr1(n),arr2(n);
        arr1[0]=nums[0];
        for(int i=1;i<n;i++){
            arr1[i]=max(arr1[i-1],nums[i]);
        }
        arr2[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            arr2[i]=max(arr2[i+1],nums[i]);
        }

        long long ans=0;
        for(int i=1;i<n-1;i++){
            long long val=1LL*(arr1[i-1]-nums[i])*arr2[i+1];
            ans=max(ans,val);
        }
        return ans;
    }
};