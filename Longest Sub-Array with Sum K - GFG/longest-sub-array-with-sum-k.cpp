//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) {
        unordered_map<int, int> umap;
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum==k){
                maxi=i+1;
            }
            
            if(umap.find(sum)==umap.end()){
                umap[sum] = i;
            }
            
            if(umap.find(sum-k)!=umap.end()){
                maxi = max(maxi, i-umap[sum-k]);
            }
        }
        return maxi;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends