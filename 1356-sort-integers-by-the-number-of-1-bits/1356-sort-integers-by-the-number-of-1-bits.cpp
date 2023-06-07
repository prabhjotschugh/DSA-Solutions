class Solution {
public:
    static bool comparator(pair<int, int> a, pair<int, int> b){
        if(a.second < b.second) return true;
        else if(a.second > b.second) return false;
        else if(a.first < b.first) return true;
        else return false;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<pair<int, int>> v;
        for(auto i: arr){
            int ones = __builtin_popcount(i);
            v.push_back({i, ones});
        }
        
        sort(v.begin(), v.end(), comparator);
        
        for(auto i: v){
            ans.push_back(i.first);
        }
        
        return ans;
    }
};