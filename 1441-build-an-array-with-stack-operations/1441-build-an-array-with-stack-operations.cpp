class Solution {
public:
    vector<string> buildArray(vector<int>& a, int n) {
        vector<string>ans;
        int i,c=1;

        for(i=0;i<a.size();i++){
            while( i<a.size() and c!=a[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
    
                c++;
            }
            c++;
            ans.push_back("Push");
        }

        return ans;
    }
};