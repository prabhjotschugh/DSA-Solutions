#include<unordered_map>
#include<algorithm>
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> umap;
        for(int i:arr){
            umap[i]++;
        }
        unordered_set<int> freq;
        for(auto [key,value]:umap){
            freq.insert(value);
        }
        if(freq.size()==umap.size()){
            return true;
        }else{
            return false;
        }
    }
};