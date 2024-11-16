class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        vector<int>ans;
        bool flag=true;
        int j=1;
        int i=0;
        while(j<nums.size()) {
            while(j<nums.size()) {
                if(nums[j]!=nums[j-1]+1) {
                        flag=false;
                        break;
                    }
                j++;
            }
            int count=j-i+1-k;
            
            while(count>0) {
                ans.push_back(nums[i+k-1]);
                count--;
                i++;
            }
           
            while(i<j && i+k<=nums.size()) {
                ans.push_back(-1);
                i++;
            }
            flag=true;
            j++;

        }
        return ans; 
    }
};