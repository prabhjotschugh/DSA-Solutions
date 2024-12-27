class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = INT_MIN,maxi = values[0];

        for(int i=1; i<values.size(); i++){
            maxi--;
            res = max(res,maxi+values[i]);
            maxi = max(values[i],maxi);
        }
        return res;
    }
};