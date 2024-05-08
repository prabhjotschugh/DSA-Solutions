class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> nums;
        vector<string> ans;
        nums = score;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end()); 
        unordered_map<int, string> m;
        for(int i=0; i<nums.size(); ++i){   
            if(i>2)
                m[nums[i]] = to_string(i+1);

            else if(i==0)
                m[nums[i]] = "Gold Medal";

            else if(i==1)
                m[nums[i]] = "Silver Medal";

            else if(i==2)
                m[nums[i]] = "Bronze Medal";
        }

        for(int i=0; i<score.size(); ++i)
            ans.push_back( m[score[i]] );

        return ans;
    }
};