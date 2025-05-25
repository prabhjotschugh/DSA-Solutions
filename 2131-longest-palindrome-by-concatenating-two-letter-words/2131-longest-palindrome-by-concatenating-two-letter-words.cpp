class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>m;
        int n = words.size();
        bool flag = true;
        int count = 0;
        for(string s : words){
            m[s]++;
        }
        for(int i=0;i<n;i++){
            if(m[words[i]]){
                if(words[i][1] == words[i][0]){
                    count+= (m[words[i]]/2)*4;
                    if(m[words[i]]%2 == 1) flag = false;
                }
                else{
                    string temp = "";
                    temp += words[i][1];
                    temp += words[i][0];
                    count += min(m[words[i]],m[temp])*4;
                    m[temp] = 0;
                }
                m[words[i]]=0;
                }
            }
        if(!flag) count+=2;
        return count;
    }
};