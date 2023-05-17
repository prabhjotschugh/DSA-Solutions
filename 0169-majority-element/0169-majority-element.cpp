class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        
        int ans;
        for(auto i:umap){
            if(i.second > nums.size()/2)    ans = i.first;
        }
        return ans;
    }
};