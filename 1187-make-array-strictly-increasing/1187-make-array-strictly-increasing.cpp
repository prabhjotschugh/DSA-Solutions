class Solution {
private:
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
    
            if (hash1 != hash2) {
                return hash1 ^ hash2;             
            }

            return hash1;
        }
    };
    int helper(int idx, int prev, vector<int> &arr1, vector<int> &arr2, unordered_map<pair<int, int>, int, hash_pair> &dp, unordered_map<int, int> &greater) {
        //Base case
        if(idx == arr1.size()) {
            return 0;
        }

        //Explore all paths;
        if(dp.find({idx, prev}) != dp.end()) {
            return dp[{idx, prev}];
        }
        int replace = 1e9, not_replace = 1e9;

        //Replace
        int i = greater[prev];
        if(i < arr2.size()) {
            replace = 1 + helper(idx + 1, arr2[i], arr1, arr2, dp, greater);            
        }

        //Not replace
        if(arr1[idx] > prev) {
            not_replace = helper(idx + 1, arr1[idx], arr1, arr2, dp, greater);
        }

        return dp[{idx, prev}] = min(replace, not_replace);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        unordered_map<pair<int, int>, int, hash_pair> dp;
        sort(arr2.begin(), arr2.end());
        unordered_map<int, int> greater;
        greater[-1] = 0; //initially previous is -1
        for(auto &num: arr1) {
            int idx = upper_bound(arr2.begin(), arr2.end(), num) - arr2.begin();
            greater[num] = idx;
        }
        for(auto &num: arr2) {
            int idx = upper_bound(arr2.begin(), arr2.end(), num) - arr2.begin();
            greater[num] = idx;
        }
        int res = helper(0, -1, arr1, arr2, dp, greater);
        return res >= 1e9 ? -1 : res;
    }
};