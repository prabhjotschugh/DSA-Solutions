class Solution {
public:
    bool isCircularSentence(string sentence) {
        int size = sentence.length();
        for(int i=0; i<size; i++){
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1]){
                return false ;
            }
        }
        return sentence[0] == sentence[size-1] ;
    }
};