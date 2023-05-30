//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int l=0;
	    int r=n-1;
	    while(l<=r){
	        int mid = l + (r-l)/2;
	        int prev = (mid-1+n)%n;
	        int next = (mid+1)%n;
	        if(arr[mid] <= arr[prev] and arr[mid] <= arr[next]){
	            return mid;
	        }
	        
	        if(arr[mid] <= arr[r]){
	            r = mid-1;
	        }else if(arr[l] <= arr[mid]){
	            l = mid+1;
	        }
	    }
	    return 0;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends