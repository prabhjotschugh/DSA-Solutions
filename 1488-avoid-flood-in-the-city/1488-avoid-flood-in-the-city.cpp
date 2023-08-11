class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> zeroIndex;
        unordered_map<int, int> umap;
        vector<int> ans(n, -1);
        
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                zeroIndex.insert(i);
                ans[i] = 1;
            }else{
                if(umap.find(rains[i]) != umap.end()){
                    auto it = zeroIndex.upper_bound(umap[rains[i]]);
                    
                    if(it == zeroIndex.end()){
                        return {};
                    }else{
                        ans[*it] = rains[i];
                        zeroIndex.erase(it);
                    }
                }
                umap[rains[i]] = i;
            }
        }
        return ans;
    }
};