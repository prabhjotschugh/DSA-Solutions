class Solution {
public:
    int binary_search(vector<int>& nums, int k, int l, int r){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==k){
                return mid;
            }
            else if(nums[mid] < k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int mini=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;
            if(nums[mid] <= nums[prev] and nums[mid] <= nums[next]){
                mini = mid;
                break;
            }
            if(nums[mid] <= nums[r]){
                r=mid-1;
            }
            else if(nums[l] <= nums[mid]){
                l = mid+1;
            }
        }
        //cout<<mini<<" "<<nums[mini]<<endl;
        int ans1 = binary_search(nums, target, 0, mini-1);
        int ans2 = binary_search(nums, target, mini, n-1);
        
        //cout<<ans1<<" "<<ans2<<endl;
        if(ans1 != -1) return ans1;
        else return ans2;
        
        
    }
};