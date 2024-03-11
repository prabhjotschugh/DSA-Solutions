class Solution {
public:
    string customSortString(string order, string s) {
        int freq[26];
        bitset<26> used=0;
        for (char c: order)
            used[c-'a']=1;
        string ans;

        for (char c: s) {
            freq[c-'a']++; 
            if (used[c-'a']==0)
                ans.push_back(c);
        }
        for (char c: order ) 
            ans+=string(freq[c-'a'], c);
        return ans;
    }
};