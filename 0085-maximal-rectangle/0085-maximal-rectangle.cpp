class Solution {
public:
        vector<int> nearestSmallerToLeft(int n, vector<int>& arr){
        vector<int> ans;
        stack<pair<int, int>> st;
        
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
    
    vector<int> nearestSmallerToRight(int n, vector<int>& arr){
        vector<int> ans;
        stack<pair<int, int>> st;
        
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
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> left = nearestSmallerToLeft(n, heights);
        vector<int> right = nearestSmallerToRight(n, heights);
        
        vector<int> width(n, 0);
        for(int i=0;i<n;i++){
            width[i] = right[i] - left[i] - 1;
        }
        
        vector<int> area(n, 0);
        for(int i=0;i<n;i++){
            area[i] = heights[i]*width[i];
        }
        
        return *max_element(area.begin(), area.end());
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int j=0;j<m;j++){
            matrix[0][j] == '0' ? v.push_back(0) : v.push_back(1);
        }
        
        int maxi = largestRectangleArea(v);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }else{
                    v[j]++;
                }
            }
            maxi = max(maxi, largestRectangleArea(v));
        }
        return maxi;
    }
};