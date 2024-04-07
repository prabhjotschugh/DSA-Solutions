class Solution {
private:
    int len;
    void generateSent(int i, string& str, unordered_set<string>& words, string temp, vector<string>& ans){
        if(i == len){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

        string s = "";

        for(int j=i; j<len; j++){
            s += str[j];
            if(words.find(s) != words.end()){
                s += ' ';
                generateSent(j+1,str,words,temp+s,ans);
                s.pop_back();
            }
        }
        return;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        len = s.size();
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        vector<string> ans;
        generateSent(0,s,words,"",ans);
        return ans;
    }
};