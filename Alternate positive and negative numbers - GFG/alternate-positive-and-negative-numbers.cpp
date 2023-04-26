//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> pos;
	    vector<int> neg;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0){
	            pos.push_back(arr[i]);
	        }else{
	            neg.push_back(arr[i]);
	        }
	    }
	    
	    int i=0, index1=0, index2=0;
	    while(index1<pos.size() && index2<neg.size()){
	        arr[i++]=pos[index1++];
	        arr[i++]=neg[index2++];
	    }
	    while(index1<pos.size()){
	        arr[i++]=pos[index1++];
	    }
	    while(index2<neg.size()){
	        arr[i++]=neg[index2++];
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends