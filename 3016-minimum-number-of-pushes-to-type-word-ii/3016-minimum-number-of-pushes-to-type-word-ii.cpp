class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        vector<int> freq(26,0);
        for(auto it: word){
            freq[it-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>()); 
        for(int i=0;i<26;i++){
            if(i<8){
                ans+= freq[i]; 
            }
            else if(i<16){
                ans+= freq[i]*2; 
            }else if(i<24){
                ans+= freq[i]*3; 
            }
            else ans+= freq[i]*4; 
        
        }
        return ans;
    }
};