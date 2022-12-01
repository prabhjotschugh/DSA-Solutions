class Solution {
public:
    int ans=0;
    int si;
    int longestStr(string s, int i){
        unordered_set<char> freq;
        for(int j=i;j<s.length();j++){
            //unordered_set<char> freq;
            
            if(freq.count(s[j])){
                si=freq.size();
                break;
            }else{
                freq.insert(s[j]);
            }
        }
        return freq.size();
    }
    
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
            int len = longestStr(s,i);
            if(len>ans){
                ans=len;
            }
        }
        return ans;
    }
};