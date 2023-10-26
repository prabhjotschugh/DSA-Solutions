class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int mod =1e9+7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> mp;
        long long ans = 0;

        for (int x: arr) {
            mp[x]=1;
            int sqrt_x=sqrt(x);

            #pragma unroll
            for (int j=0;  arr[j]<=sqrt_x; j++){
                int y=arr[j];
                if (x % y == 0){
                    int z=x/y;
                    int c=(y==z)?1:2;
                    if (mp.count(z))
                        mp[x]=(mp[x]+mp[y]*mp[z]*c)%mod;
                }
                   
            }
                
            ans = (ans + mp[x]) % mod;
        }
        return ans;
    }
};