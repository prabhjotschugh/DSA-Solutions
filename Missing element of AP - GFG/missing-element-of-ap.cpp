//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMissing(int arr[], int n) {
        // code here
        int a, l, s=0;
        a=arr[0];
        l=arr[n-1];
      
        if((a+l)%2==0) {
            s = (a+l)/2;
            s = s*(n+1);
        }else{
            s = (n+1)/2;
            s = (a+l)*s;
        }
        
        int arr_sum = 0;
        for(int i=0;i<n;i++){
            arr_sum+=arr[i];
        }
        return (s-arr_sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMissing(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends