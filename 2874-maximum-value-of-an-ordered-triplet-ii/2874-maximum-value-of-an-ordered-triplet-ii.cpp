#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n), suffix(n);
        prefixMax(prefix, nums);
        suffixMax(suffix, nums);
        long long ans = 0;
        
        for (int j = 1; j < n - 1; j++) {
            ans = max(ans, (prefix[j - 1] - nums[j]) * suffix[j + 1]);
        }
        
        return ans;
    }
    
private:
    void prefixMax(vector<long long>& prefix, vector<int>& nums) {
        long long maxVal = prefix[0] = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            maxVal = max(maxVal, (long long)nums[i]);
            prefix[i] = maxVal;
        }
    }
    
    void suffixMax(vector<long long>& suffix, vector<int>& nums) {
        long long maxVal = suffix[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            maxVal = max(maxVal, (long long)nums[i]);
            suffix[i] = maxVal;
        }
    }
};