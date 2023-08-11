class Solution {
public:
    vector<int> partitionLabels(string s) {
        int freq[26] = {};
        map<char,int> mp;
        vector<int> ans;
        int sz = 0;
        for(char ch : s) 
            freq[ch-'a']++;
        
        for(char ch : s){
            if(!mp.count(ch)){
                if(freq[ch-'a']-1) 
                    mp.insert({ch,freq[ch-'a']-1});
                
                sz += freq[ch-'a'];
            }    
            else if(--mp[ch] == 0) 
                mp.erase(ch);
            
            if(size(mp) == 0){
                ans.push_back(sz);
                sz = 0;
            }
        }
        return ans;
    }
};