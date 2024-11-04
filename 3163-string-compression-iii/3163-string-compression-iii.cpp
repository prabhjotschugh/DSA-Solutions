class Solution {
public:
    string compressedString(string word) {
        string ans;
        int n=word.size();
        int i=0;

        while(i<n){
            char cur=word[i];
            int count=0;

            while(i<n && word[i]==cur && count<9){
                count++;
                i++;
            }
            ans+=to_string(count)+cur;
        }
        return ans;
    }
};