class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int resultSize = l.size();
        vector<bool> result(resultSize);
          for(int resIndx = 0; resIndx < resultSize; resIndx++){ 
            int left = l[resIndx], right = r[resIndx];
            vector<int> rArr;
            for(int numsIndx = left; numsIndx <= right; numsIndx++){
                rArr.push_back(nums[numsIndx]);
            }
            if(isArith(rArr)){
                result[resIndx] = true;
            }else{
                result[resIndx] = false;
            }
          }  
        return result; 
    }
private:    
    bool isArith(vector<int> & rArr){
        sort(rArr.begin(), rArr.end());
        int diff = rArr[1] - rArr[0];
        for(int indx = 1; indx < rArr.size(); indx++){
            if(diff != rArr[indx] - rArr[indx - 1]){
                return false;
            }
        }
        return true;    
    }  
};