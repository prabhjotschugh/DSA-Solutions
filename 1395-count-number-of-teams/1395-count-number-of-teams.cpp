class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> smallest(n, 0);
        vector<int> largest(n, 0);
        for(int i = 0 ; i < n ; i++){
            for(int j = i - 1 ; j >= 0 ; j--){
                if(rating[i] > rating[j]) smallest[i]++;
                if(rating[i] < rating[j]) largest[i]++;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i - 1 ; j >= 0 ; j--){
                if(rating[i] > rating[j]) ans += smallest[j];
                if(rating[i] < rating[j]) ans += largest[j];
            }
        }
        return ans;
    }
};