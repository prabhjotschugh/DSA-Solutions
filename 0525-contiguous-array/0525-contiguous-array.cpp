class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int left = 0, right = 0, len = nums.size();
        for(int indx = 0; indx < len; indx++){
            if(nums[indx] == 0) 
                nums[indx]  = -1;
        }
        int prefSum = 0;
        unordered_map<int, int> prefSumIndxMp;
        prefSumIndxMp[0] = -1;
        int maxSubLen = 0;
        for(int indx = 0; indx < len; indx++){
            prefSum += nums[indx];
            if(prefSumIndxMp.find(prefSum - 0) != prefSumIndxMp.end()){
                maxSubLen = max(maxSubLen, indx - prefSumIndxMp[prefSum - 0]);
            }
            if(prefSumIndxMp.find(prefSum) == prefSumIndxMp.end()) {
                prefSumIndxMp[prefSum] = indx;
            }
        }
        return maxSubLen;
    }
};