//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        // Your code goes here   
        int n=s.length();
        int i=0;
        int j=0;
        int len = INT_MAX;
        int mini=0;
        int req=0;
        vector<int> freq(128, 0);
        for(int i=0;i<n;i++){
            if(freq[s[i]] == 0){
                freq[s[i]]++;
                req++;
            }
        }
        
        while(j < n){
            if(freq[s[j++]]-- > 0){
                req--;
            }
            
            while(req == 0){
                len = min(len, j-i);
                
                if(freq[s[i++]]++ == 0){
                    req++;
                }
            }
        }
        return len;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends