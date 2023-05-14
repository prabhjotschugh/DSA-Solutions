class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int i = 0;
        int j = 0;
        int count = 0;
        while(j < magazine.size()) {
            if(ransomNote[i] == magazine[j]) {
                count++;
                i++;
                j++;
            }
            else j++;
        }
        return count == ransomNote.size();
    }
};