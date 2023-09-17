class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size=nums.size();
        vector<unordered_map<int,int>>map(size);
        int ans=0;
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                long long diff=(long long)nums[i]-(long long)nums[j];
                if(diff>INT_MAX || diff<INT_MIN)continue;
                int n1=map[j][diff];
                int n2=map[i][diff];

                map[i][diff]=n1+n2+1;
                ans+=n1;
            }
        }
        return ans;
    }
};