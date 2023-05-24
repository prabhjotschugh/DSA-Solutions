//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0;
        int j=0;
        int n=s.length();
        int maxi=-1;
        int distinct=0;
        
        vector<int> freq(128, 0);
        while(j<n){
            if(freq[s[j++]]++ == 0){
                distinct++;
            }
            
            if(distinct == k){
                maxi = max(maxi, j-i);
            }else if(distinct > k){
                if(freq[s[i++]]-- == 1){
                    distinct--;
                }
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends