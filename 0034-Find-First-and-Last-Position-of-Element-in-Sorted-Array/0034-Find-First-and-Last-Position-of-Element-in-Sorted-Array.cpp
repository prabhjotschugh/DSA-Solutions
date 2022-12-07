class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int index=0;
        int arr[100000];
        int counter=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                counter++;
                arr[index]=i;
                index++;
            }
        }
        if(counter==0){
            ans.push_back(-1);
            ans.push_back(-1);
        }else{
            ans.push_back(arr[0]);
            ans.push_back(arr[counter-1]);
        }
        return ans;
    }
};