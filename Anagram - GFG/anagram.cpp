//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        unordered_map<char, int> first;
        unordered_map<char, int> second;
        
        for(int i=0;i<a.length();i++){
            first[a[i]]++;
        }
        for(int i=0;i<b.length();i++){
            second[b[i]]++;
        }
        
        if(first == second){
            return true;
        }else{
            return false;
        }
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends