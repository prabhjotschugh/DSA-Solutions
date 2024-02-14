class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        
        for (int num : nums) {
            if (num > 0) {
                positive.push_back(num);
            } else {
                negative.push_back(num);
            }
        }
        vector<int> result;
        int i = 0, j = 0;
        while (i < positive.size() && j < negative.size()) {
            result.push_back(positive[i]);
            result.push_back(negative[j]);
            i++;
            j++;
        }
        while (i < positive.size()) {
            result.push_back(positive[i]);
            i++;
        }
        while (j < negative.size()) {
            result.push_back(negative[j]);
            j++;
        }
        
        return result;
    }
};