class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>> >ans;
        
        //int final ans = 0
        //int vector<int,int> = ans(n);
        long long a = 0;
        long long n = nums.size();
        for(int i=0;i<n;i++){
            ans.push({nums[i],i});
        }
        
        vector<int> vec(n,0);
        while(!ans.empty()){
            int x = ans.top().first;
            int y = ans.top().second;
            
            ans.pop();
            if(!vec[y]){
                a = a + x;
                vec[y] = 1;
                if(y-1 >= 0){
                    vec[y-1] = 1;
                }
                
                if(y+1 < n){
                    vec[y+1] = 1;
                }
            }
        }
        return a;
    }
};