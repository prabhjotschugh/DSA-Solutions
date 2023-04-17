class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        vector<bool> ans;
        for(int a : candies)
            maxi = max(maxi,a);
        
        for(int a : candies){
            if(a+extraCandies >= maxi) 
                ans.push_back(true);
            else 
                ans.push_back(false);
        }
        return ans;
    }
};