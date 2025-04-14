class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        const int n=arr.size();
        int cnt=0;
        for(int i=0; i<n-2; i++){
            const int x=arr[i];
            for(int j=i+1; j<n-1; j++){
                const int y=arr[j];
                if (abs(x-y)>a) continue;
                for(int k=j+1; k<n; k++){
                    const int z=arr[k];
                    if (abs(y-z)>b) continue;
                    cnt+=abs(abs(x-z))<=c;
                }
            }
        }
        return cnt;
    }
};