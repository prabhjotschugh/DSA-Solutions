class Solution {
public:
    int brute(vector < int > & nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
          for (int j = i + 1; j < n; j++)
            cnt += (nums[i] == nums[j]);
        }
        return cnt;
    }
    
    int better(vector < int > & nums) {
        int n = nums.size(), cnt = 0;
        unordered_map < int, int > mp;
        
        for (auto & it: nums)
            mp[it]++;
        
        for (auto & pair: mp) {
            n = pair.second;
            cnt += ((n) * (n - 1)) / 2;
        }
        return cnt;
    }
    
    int numIdenticalPairs(vector < int > & nums) {
        return better(nums);
    }
};