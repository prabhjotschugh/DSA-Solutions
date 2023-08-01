//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string, int> umap;
    int solve(string s, int i, int j, bool isTrue){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(isTrue)  return s[i]=='T';
            else        return s[i]=='F';
        }
        string temp = to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isTrue));
        
        if(umap.find(temp) != umap.end()){
            return umap[temp];
        }
        
        int ans = 0;
        for(int k=i+1;k<j;k+=2){
            int leftTrue = solve(s, i, k-1, true);
            int leftFalse = solve(s, i, k-1, false);
            int rightTrue = solve(s, k+1, j, true);
            int rightFalse = solve(s, k+1, j, false);
            
            if(s[k]=='&'){
                if(isTrue){
                    ans += leftTrue*rightTrue;
                }else{
                    ans += leftTrue*rightFalse + leftFalse*rightTrue + leftFalse*rightFalse;
                }
            }
            else if(s[k]=='|'){
                if(isTrue){
                    ans += leftTrue*rightTrue + leftTrue*rightFalse + leftFalse*rightTrue;
                }else{
                    ans += leftFalse*rightFalse;
                }
            }else if(s[k]=='^'){
                if(isTrue){
                    ans += leftTrue*rightFalse + leftFalse*rightTrue;
                }else{
                    ans += leftTrue*rightTrue + leftFalse*rightFalse;
                }
            }
        }
        return umap[temp] = ans%1003;
    }
    
    int countWays(int n, string s){
        // code here
        return solve(s, 0, n-1, true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends