//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
#define mod 1000000007
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        int dp[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0)
                    dp[i][j] = 0;
                    
                if(j==0)
                    dp[i][j] = 1;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod;
                }else if(arr[i-1] > j){
                    dp[i][j] = dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][sum]%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends