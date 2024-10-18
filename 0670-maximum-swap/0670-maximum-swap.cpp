class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        string nums2 = nums;
        
        sort(nums2.rbegin(), nums2.rend());
        
        unordered_map<char, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums2[i]) {
                swap(nums[i], nums[mp[nums2[i]]]);
                break; 
            }
        }
        
        return stoi(nums);
    }
};