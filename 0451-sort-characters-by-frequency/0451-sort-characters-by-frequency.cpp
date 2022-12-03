#include<unordered_map>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap;
        for(auto i:s){
            umap[i]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto i:umap){
            pq.push({i.second, i.first});
        }
        
        string ans = "";
        while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();
            
            while(p.first--){
                ans+=p.second;
            }
        }
        return ans;
    }
};