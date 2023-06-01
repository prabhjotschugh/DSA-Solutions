//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

bool isValid(int arr[], int n, int k, int maxCapacity){
    int sum=0;
    int students=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum > maxCapacity){
            students++;
            sum = arr[i];
        }
        
        if(students > k){
            return false;
        }
    }
    return true;
}

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int k){
        if(n < k){
            return -1;
        }
        long long int sum=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi = max(maxi, arr[i]);
            sum+=arr[i];
        }
        
        int l = maxi;
        int r = sum;
        int ans=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(isValid(arr, n, k, mid) == true){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends