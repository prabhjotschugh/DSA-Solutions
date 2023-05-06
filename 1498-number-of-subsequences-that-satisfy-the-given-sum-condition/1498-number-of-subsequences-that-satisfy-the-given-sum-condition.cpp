class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int count =0 ; 
        int n = nums.size();
        vector<int>pow(n,1);
        sort(nums.begin(), nums.end());
        for(int i =1;i<n;i++){
            pow[i] = (pow[i-1] * 2) % (1000000007 );
        }
        int left =0 ; int right = n-1;
        while(left<=right){
            if(nums[left]  + nums[right] > target) right--;
            else{
                count  = (count + pow[right-left] ) % (1000000007 );
                left++;
            }
        }
        return count;
    }
};