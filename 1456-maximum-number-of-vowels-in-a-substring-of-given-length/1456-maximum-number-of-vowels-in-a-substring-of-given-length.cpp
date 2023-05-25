class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;
        int n=s.length();
        int counter=0;
        int maxi=0;
        
        while(j<n){
            if(isVowel(s[j])){
                counter++;
            }
            
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                maxi = max(maxi, counter);
                
                if(isVowel(s[i])){
                    counter--;
                }
                i++;
                j++;
            }
        }
        return maxi;
    }
};