class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> ele(nums.begin(), nums.end());
        
        if(ele.size() < 3){
            return *max_element(nums.begin(), nums.end());
        }
        
        set<int>::iterator it = ele.end();
        advance(it, -3);
        
        return *it;
    }
};