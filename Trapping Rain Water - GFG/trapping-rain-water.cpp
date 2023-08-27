//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        vector<int> maxiLeft(n, 0);
        vector<int> maxiRight(n, 0);
        
        maxiLeft[0] = height[0];
        for(int i=1;i<n;i++){
            maxiLeft[i] = max(maxiLeft[i-1], height[i]);
        }
        
        maxiRight[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            maxiRight[i] = max(maxiRight[i+1], height[i]);
        }
        
        vector<int> water(n, 0);
        for(int i=0;i<n;i++){
            water[i] = min(maxiLeft[i], maxiRight[i]) - height[i];
        }
        
        long long ans=0;
        for(int i=0;i<n;i++){
            ans += water[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends