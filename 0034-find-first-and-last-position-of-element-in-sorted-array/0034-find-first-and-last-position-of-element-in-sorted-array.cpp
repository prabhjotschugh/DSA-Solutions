class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int firstOcc = -1, lastOcc = -1;
        vector<int> ans;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                firstOcc = mid;
                r = mid-1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        
        l=0;
        r=n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                lastOcc = mid;
                l = mid+1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        ans.push_back(firstOcc);
        ans.push_back(lastOcc);
        return ans;
    }
};