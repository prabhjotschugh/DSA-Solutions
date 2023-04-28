class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> minFreq;
        for(char ch='a'; ch<='z';ch++){
            minFreq[ch]=1000;
        }
        vector<string> ans;
        
        for(auto word: words){
            unordered_map<char, int> freq;
            for(auto letter: word){
                freq[letter]++;
            }
            for(char letter='a'; letter<='z';letter++){
                minFreq[letter] = min(minFreq[letter], freq[letter]);
            }
        }
        for(char ch='a'; ch<='z';ch++){
            while(minFreq[ch] > 0){
                ans.push_back(string(1, ch));
                minFreq[ch]--;
            }
        }
        return ans;
    }
};