//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> nearestSmallerToLeft(int n, long long arr[]){
        vector<long long> ans;
        stack<pair<long long, int>> st;
        
        for(int i=0;i<n;i++){
            while(st.size() > 0 && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.size() == 0){
                ans.push_back(-1);
            }
            else if(st.top().first < arr[i]){
                ans.push_back(st.top().second);
            }
            st.push({arr[i], i});
        }
        return ans;
    }
    
    vector<long long> nearestSmallerToRight(int n, long long arr[]){
        vector<long long> ans;
        stack<pair<long long, int>> st;
        
        for(int i=n-1;i>=0;i--){
            while(st.size() > 0 && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.size() == 0){
                ans.push_back(n);
            }
            else if(st.top().first < arr[i]){
                ans.push_back(st.top().second);
            }
            st.push({arr[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    long long getMaxArea(long long heights[], int n) {
        
        vector<long long> left = nearestSmallerToLeft(n, heights);
        vector<long long> right = nearestSmallerToRight(n, heights);
        
        vector<long long> width(n, 0);
        for(int i=0;i<n;i++){
            width[i] = right[i] - left[i] - 1;
        }
        
        vector<long long> area(n, 0);
        for(int i=0;i<n;i++){
            area[i] = heights[i]*width[i];
        }
        
        return *max_element(area.begin(), area.end());
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends