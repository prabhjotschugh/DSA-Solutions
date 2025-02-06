class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        const int n=nums.size();
        unordered_map<int, int> freq;
        freq.reserve(n*(n-1)/2);
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                freq[nums[i]*nums[j]]++;
        
        int ans=0;
        for(auto& [x, f]: freq){ 
            if (f>1) ans+=f*(f-1)*4;
        }
        return ans;
    }
};