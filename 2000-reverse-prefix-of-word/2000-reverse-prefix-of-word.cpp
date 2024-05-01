class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int index = word.find(ch);
        if(index == -1){
            return word;
        }
        else{
            string first = word.substr(0 , index+1);
            reverse(first.begin(),first.end());
            string last = word.substr(index+1);

            string final_ = first + last;
            return final_;
        }
    }
};