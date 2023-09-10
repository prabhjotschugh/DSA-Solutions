class Solution {
public:
    int maxCoins(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans = 0;
        for(int i = 0,j = arr.size()-1;i<j;j-=2,i+=1)
        ans+=arr[j-1];
        return ans; 
    }
};