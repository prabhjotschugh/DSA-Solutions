class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        vector<char>ans(s.size() ,'0');
        int j=0;
        for(int i=0;i<s.length() ; i++){
            if(s[i]== '1'){
                ans[j++]=s[i];
            }
        }
        string sol="";
        swap(ans[j-1],ans[s.size()-1]);
        for(auto x :ans){
            sol+=x;
        }
        return sol;
    }
};