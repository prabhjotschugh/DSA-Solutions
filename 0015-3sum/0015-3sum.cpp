class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            if(i == 0|| (i>0 && nums[i]!= nums[i-1])){
                int rem = -nums[i];
                int l=i+1;
                int r=n-1;

                while(l<r){
                    if(nums[l] + nums[r] == rem){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        ans.push_back(temp);

                        while(l<r and nums[l] == nums[l+1]){
                            l++;
                        }
                        while(l<r and nums[r] == nums[r-1]){
                            r--;
                        }
                    }

                    if(nums[l] + nums[r] < rem){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};