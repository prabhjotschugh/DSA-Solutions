//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static int comparator(pair <pair<int, int>, int> a, pair <pair<int, int>, int> b){
        return a.first.second < b.first.second;
    }
    vector<int> maxMeetings(int n,vector<int> &s,vector<int> &f){
        vector<pair < pair<int, int>, int> > v;
        for(int i=0;i<n;i++){
            v.push_back({ {s[i], f[i]}, i+1});
        }
        
        sort(v.begin(), v.end(), comparator);
        
        vector<int> ans;
        ans.push_back(v[0].second);
        int prevEndTime = v[0].first.second;
        for(int i=1;i<n;i++){
            if(v[i].first.first > prevEndTime){
                ans.push_back(v[i].second);
                prevEndTime = v[i].first.second;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends