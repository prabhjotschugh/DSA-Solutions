class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>mp1 ;
        map<int,int>mp2 ;
        for(auto &x : target){
            mp1[x]++;
        }
        for(auto &x : arr){
            mp2[x]++;
        }
        auto it2 = mp2.begin() ;
        for(auto & it1 :mp1){
            if(it1.first != it2->first || it1.second != it2->second)return false ;
            it2++;
        }
        return true ;
    }
};