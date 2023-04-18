//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int makeProductOne(int arr[], int N) {
        // code here
        int ans=0;
        int pos=0, neg=0, zero=0;
        for(int i=0;i<N;i++){
            if(arr[i]>0){
                ans+=(arr[i]-1);
                arr[i]=1;
                pos++;
            }
            else if(arr[i]<0){
                ans+=abs(arr[i]+1);
                arr[i]=-1;
                neg++;
            }else{
                zero++;
            }
        }
        
        if(neg%2==0){
            return ans+zero;
        }else{
            if(zero>0){
                return ans+zero;
            }else{
                return ans+2;
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.makeProductOne(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends