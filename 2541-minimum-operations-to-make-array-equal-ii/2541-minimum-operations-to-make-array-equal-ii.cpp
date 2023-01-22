#define ll long long int
#define value 100000
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        ll n = nums1.size();
        ll arr[value] = {0};
        bool flag=0;
        for(int i=0;i<n;i++){
            if(nums1[i]!=nums2[i]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            arr[i] = nums1[i]-nums2[i];
        }
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum!=0){
            return -1;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                ans+=arr[i];
            }
        }
        
        if(k!=0 && ans%k==0){
            return ans/k;
        }else{
            return -1;
        }
    }
};