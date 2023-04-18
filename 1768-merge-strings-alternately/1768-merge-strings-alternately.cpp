class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len = word1.length() + word2.length();
        string ans(2*len, ' ');
        for(int i=0;i<word1.length();i++){
            ans[2*i] = word1[i];
        }
        
        for(int i=0;i<word2.length();i++){
            ans[2*i+1] = word2[i];
        }
        ans.erase(remove(ans.begin(), ans.end(), ' '), ans.end());
        return ans;
    }
};