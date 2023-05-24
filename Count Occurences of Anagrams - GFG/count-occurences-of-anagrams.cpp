//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pattern, string text) {
	    int i=0;
	    int j=0;
	    int n=text.length();
	    int k=pattern.length();
	    int counter=0;
	    
	    vector<int> desired(128, 0);
	    vector<int> required(128, 0);
	    for(int i=0;i<k;i++){
	        desired[pattern[i]]++;
	    }
	    
	    while(j<n){
	        required[text[j]]++;
	        
	        if(j-i+1 < k){
	            j++;
	        }
	        else if(j-i+1 == k){
	            if(desired == required){
	                counter++;
	            }
	            
	            required[text[i]]--;
	            i++;
	            j++;
	        }
	    }
	    return counter;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends