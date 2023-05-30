//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) {
	    int l = 0, r = n-1;
        int firstOcc = -1, lastOcc = -1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                firstOcc = mid;
                r = mid-1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        
        l = 0; r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                lastOcc = mid;
                l = mid+1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if(lastOcc == -1 or firstOcc == -1){
            return 0;
        }
        int ans = lastOcc - firstOcc + 1;
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends